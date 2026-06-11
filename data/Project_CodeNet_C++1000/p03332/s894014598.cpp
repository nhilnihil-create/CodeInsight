#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

// const ll mod = 1000000007;
const ll mod = 998244353;

const int MAX_N = 300010;
ll fact[MAX_N],fact_inv[MAX_N],inv[MAX_N];

ll pow(ll a,ll b) {
    ll ret;
    if (b == 0) ret = 1;
    else if (b == 1) ret = a;
    else {
        ll c = pow(a,b/2);
        if (b%2) ret = (c*c)%mod*a%mod;
        else ret = c*c%mod;
    }
    return ret;
}

void create_table(int n) {
    fact[0] = 1;fact[1] = 1;
    for (int i = 2;i <= n;++i) fact[i] = fact[i-1]*i%mod;
    fact_inv[n] = pow(fact[n],mod-2);
    for (int i = n;i > 0;--i) fact_inv[i-1] = fact_inv[i]*i%mod;
    for (int i = 1;i <= n;++i) inv[i] = fact_inv[i]*fact[i-1]%mod;
}

ll combi(ll a, ll b) {
    return fact[a]*fact_inv[b]%mod*fact_inv[a-b]%mod;
}

int main() {
    ll n,a,b,k;
    cin >> n >> a >> b >> k;
    create_table(n);
    ll ans = 0;
    for (int i = 0;i <= n;++i) if (k >= a*i && (k-a*i)%b == 0 && (k-a*i)/b <= n) {
        ans += combi(n,i)*combi(n,(k-a*i)/b)%mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}