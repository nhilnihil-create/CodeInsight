#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N, K;
    cin >> N >> K;
    ll a[N];
    rep(i, N) cin >> a[i];
    vector<ll> v;
    ll sum[N+1];
    sum[0] = 0;
    rep2(i, 1, N) sum[i] = sum[i-1]+a[i-1];
    rep(i, N+1){
        rep2(j, i+1, N) v.pb(sum[j]-sum[i]);
    }
    ll ans = 0;
    rep3(i, 40, 0){
        int cnt = 0;
        for(auto &e: v) if(e & (1ll<<i)) cnt++;
        if(cnt < K) continue;
        ans |= 1ll<<i;
        for(auto &e: v) if(!(e & (1ll<<i))) e = 0;
    }
    cout << ans << endl;
}