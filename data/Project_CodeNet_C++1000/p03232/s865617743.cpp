#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

const ll mod = 1000000007;
//const ll mod = 998244353;

const int MAX_N = 100010;
ll fact[MAX_N],fact_inv[MAX_N],inv[MAX_N];

ll pow_mod(ll a,ll b) {
    ll ret;
    if (b < 0) ret = pow_mod(a,mod+b-1);
    else if (b == 0) ret = 1;
    else if (b == 1) ret = a;
    else {
        ll c = pow_mod(a,b/2);
        if (b%2) ret = (c*c)%mod*a%mod;
        else ret = c*c%mod;
    }
    return ret;
}

void create_table(int n) {
    fact[0] = 1;fact[1] = 1;
    for (int i = 2;i <= n;++i) fact[i] = fact[i-1]*i%mod;
    fact_inv[n] = pow_mod(fact[n],mod-2);
    for (int i = n;i > 0;--i) fact_inv[i-1] = fact_inv[i]*i%mod;
    for (int i = 1;i <= n;++i) inv[i] = fact_inv[i]*fact[i-1]%mod;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    create_table(n);
    ll ans = 0;
    vector<ll> sums(n+1,0);
    for (int i = 1;i < n+1;++i) sums[i] = (sums[i-1]+inv[i])%mod;
    for (int i = 0;i < n;++i) {
        ans += (sums[i+1]+sums[n-i]-1)*a[i];
        ans %= mod;
    }
    cout << ans*fact[n]%mod << endl;
}