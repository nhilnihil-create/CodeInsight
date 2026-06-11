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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> s(n+1);
    rep(i, n) s[i+1] = s[i]+a[i];
    debug(s);
    map<ll, int> mp;
    rep(i, n+1) mp[s[i]]++;
    ll ans = 0;
    for(const auto& m: mp) {
        if (m.se>1) {
            ans += m.se*(m.se-1ll)/2ll;
        }
    }
    cout << ans << endl;
}