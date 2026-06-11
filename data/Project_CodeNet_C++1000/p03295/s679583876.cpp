#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) { return arg1.second < arg2.second; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> ab(m);

    for(int im=0;im<m;im++) {
        cin >> ab.at(im).first >> ab.at(im).second;
        ab.at(im).second--;
    }

    sort(ab.begin(), ab.end(), compPair);
    int ans = 0, abend = 0;
    for(int im=0;im<m;im++) {
        if(ab.at(im).first>abend) {
            abend = ab.at(im).second;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
