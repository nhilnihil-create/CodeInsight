#include <bits/stdc++.h>
#define ll long long
#define int long long
#define int128 __int128_t
#define Android ios::sync_with_stdio(false), cin.tie(NULL)
#define redirect_input freopen("./input.txt", "r", stdin);
#define redirect_output freopen("./output.txt", "w", stdout);
#define debug(s, r) std::cerr << #s << ": " << (s) << (r==0?' ':'\n')
#define pii pair<ll, ll>  
#define sqr(x) ((x)*(x))

using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 100;
const ll mod = 1e9 + 7;

ll n, nfac = 1;
ll a[maxn], presum[maxn];

ll inv(ll base){
    ll t = mod - 2, ret = 1;
    for(; t; t>>=1){
        if(t & 1) ret = ret * base % mod;
        base = base * base % mod;
    }
    return ret;
}

void init(){
    for(int i=2; i<=n; i++) nfac = nfac * i % mod;
    for(int i=2; i<=n; i++){
        presum[i] = (presum[i-1] + nfac * inv(i) % mod) % mod;
    }
}

void solve(){
    cin >> n;
    init();
    ll suma = 0, ans = 0;
    for(int i=1; i<=n; i++) cin >> a[i], suma = (suma + a[i]) % mod;
    for(int i=1; i<=n; i++){
        ans = (ans + (presum[i] + presum[n - i + 1]) % mod * a[i]) % mod;
    }
    ans = (ans + suma * nfac % mod) % mod;
    cout << ans << '\n';
}

signed main(){
    Android;
    solve();
}
