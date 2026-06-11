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
    vector<vector<int>> isOpen(n, vector<int>(10));
    rep(i, n) rep(j, 10) cin >> isOpen[i][j];
    vector<vector<int>> profit(n, vector<int>(11, 0));
    rep(i, n) rep(j, 11) cin >> profit[i][j];

    ll ans = -LONG_LONG_MAX;
    rep(bit, 1<<10) {
        ll tmp = 0;
        bool ok = false;
        vector<int> bothOpen(n, 0);
        rep(i, 10) {
            if (bit & 1<<i) {
                ok = true;
                rep(j, n) {
                    if (isOpen[j][i]==1) bothOpen[j]++;
                }
            }
        }
        if (ok) {
            rep(i, n) tmp += profit[i][bothOpen[i]];
            if (chmax(ans, tmp)) debug(ans, bothOpen, tmp);
        }
    }

    cout << ans << endl;

}