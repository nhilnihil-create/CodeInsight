#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n; cin >> n;
    ll m; cin >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n-1) a[i+1] += a[i];
    rep(i, n) a[i] %= m;

    map<ll, ll> mp;
    rep(i, n) mp[a[i]]++;

    ll ans = 0;
    for (auto kv: mp) {
        ll k = kv.first, v = kv.second;
        if (k == 0) ans += v * (v+1) / 2;
        else ans += v * (v-1) / 2;
    }
    cout << ans << endl;
}
