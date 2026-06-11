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
    int n, c; cin >> n >> c;
    vector<vector<int>> vec(c, vector<int>(c));
    rep(i, c) rep(j, c) cin >> vec[i][j];
    vector<vector<int>> mat(n, vector<int>(n));
    rep(i, n) rep(j, n) {cin >> mat[i][j]; mat[i][j]--;}
    vector<map<int, int>> mp(3);
    rep(i, n) rep(j, n) {
        mp[(i+j)%3][mat[i][j]]++;
    }

    ll ans = LLONG_MAX;
    rep(i, c) rep(j, c) rep(k, c) {
        if (i==j || j==k || i==k) continue;
        ll tot = 0;
        for(const auto& m: mp[0]) tot += vec[m.fi][i]*m.se;
        for(const auto& m: mp[1]) tot += vec[m.fi][j]*m.se;
        for(const auto& m: mp[2]) tot += vec[m.fi][k]*m.se;
        debug(i, j, k, tot);
        chmin(ans, tot);
    }

    cout << ans << endl;
}