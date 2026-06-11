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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    bool ok = true;
    ll ans = 0;
    if (a[0]!=0) {
        ok = false;
    } else {
        int now = -1;
        rep(i, n) {
            if (now==-1) {
                now = a[i];
            } else if (a[i]==now+1) {
                now = a[i];
            } else if (a[i]==now) {
                ans += now;
                now = a[i];
            } else if (a[i]<now) {
                ans += now;
                now = a[i];
            } else {
                ok = false;
                break;
            }
            if (i==n-1) ans += now;
            debug(now, ans);
        }
    }
    if (!ok) cout << -1 << endl;
    else cout << ans << endl;
}