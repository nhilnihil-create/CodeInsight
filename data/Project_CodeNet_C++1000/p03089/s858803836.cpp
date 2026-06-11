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
const int INF = 1e9;
const int MOD = 1e9+7;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    debug(a);
    vector<int> ans(n);
    rep(i, n) {
        vector<P> tmp;
        rep(j, n-i) {
            if (a[j]-j==1) tmp.emplace_back(a[j], j);
        }
        if (tmp.empty()) {
            cout << -1 << endl;
            return 0;
        }
        sort(tmp.rbegin(), tmp.rend());
        ans[i] = tmp.front().fi;
        a.erase(a.begin()+tmp.front().se);
        debug(ans);
        debug(a);
    }
    reverse(all(ans));
    rep(i, n) cout << ans[i] << endl;
}