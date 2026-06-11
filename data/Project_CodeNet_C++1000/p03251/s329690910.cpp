#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }


int main(void) {
    int n, m ,bx, by;
    cin >> n >> m >> bx >> by;

    vector<int> x(n);
    vector<int> y(m);
    for(int in=0;in<n;in++) {
        cin >> x.at(in);
    }
    for(int im=0;im<m;im++) {
        cin >> y.at(im);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int xmax = x.at(n-1), bz = y.at(0);

    if(bx<bz&&bz<=by&&xmax<bz) cout << "No War" << endl;
    else cout << "War" << endl;

    return 0;
}
