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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> b;
    rep(i, n) {
        ll tmp = a[i];
        b.push_back(tmp);
        FOR(j, i+1, n) {
            tmp += a[j];
            b.push_back(tmp);
        }
    }
    sort(b.rbegin(), b.rend());
    ll ans = 0;
    for(int i=40; i>=0; i--) {
        ll now = ans + (1ll<<i);
        int cnt = 0;
        rep(j, sz(b)) {
            if ((now & b[j]) == now) cnt++;
        }
        if (cnt >= k) {
            ans = now;
        }
    }
    cout << ans << endl;
}