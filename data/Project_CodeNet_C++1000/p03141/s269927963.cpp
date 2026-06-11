#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    int n; cin >> n;
    vector<pair<int, P>> a(n);
    rep(i, n) {
        int x, y; cin >> x >> y;
        a[i] = {i, {x, y}};
    }
    sort(all(a), [] (pair<int, P> &x, pair<int, P> &y) {
        return x.se.fi + x.se.se > y.se.fi + y.se.se;
    });
    ll taka = 0, aoki = 0;
    rep(i, n) {
        if (i%2==0) {
            taka += a[i].se.fi;
        } else {
            aoki += a[i].se.se;
        }
    }
    cout << taka - aoki << endl;
}