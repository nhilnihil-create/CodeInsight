#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> w(n+1);
    vector<int> e(n+1);
    for(int in=1;in<=n;in++) {
        if(s.at(in-1)=='W') { 
            w.at(in) += w.at(in-1) + 1;
            e.at(in) = e.at(in-1);
        }
        else { 
            e.at(in) += e.at(in-1) + 1;
            w.at(in) = w.at(in-1);
        }
    }

    int ans=n+10;
    for(int in=1;in<=n;in++) {
        if(in==n) ans = min(ans, w.at(in-1));
        else ans = min(ans, w.at(in-1)+e.at(n)-e.at(in));
    }

    cout << ans << endl;

    return 0;
}
