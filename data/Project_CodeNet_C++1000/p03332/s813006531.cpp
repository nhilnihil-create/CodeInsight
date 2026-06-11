#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=998244353, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

ll fac[300007],finv[300007],inv[300007];
void cominit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<300007;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
ll com(ll n,ll k){
    if(n<k)return 0;
    if(n<0 || k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cominit();
    ll n, a, b, k, ans = 0;
    cin >> n >> a >> b >> k;
    for(ll x = 0; x <= n; x++){
    	if(k >= x * a && (k - x * a) % b == 0){
    		ll y = (k - x * a) / b;
    		(ans += (com(n, x) * com(n, y)) % mod ) %= mod;
    	}
    }
    cout << ans << endl;
    return 0;
}
