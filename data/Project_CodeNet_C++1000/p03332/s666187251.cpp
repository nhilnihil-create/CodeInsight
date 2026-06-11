#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    const ll MOD = 998244353;
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    int max_number = n;
    
    vector<ll> fac(max_number+1,1);
    vector<ll> inv(max_number+1,1);
    vector<ll> finv(max_number+1,1);
    vector<ll> nCk(max_number+1,1);
    for(i = 2;i <= max_number;++i){
        inv.at(i) = MOD - inv.at(MOD%i)*(MOD/i)%MOD;
    }
    for(i = 1;i <= max_number;++i){
        fac.at(i) = fac.at(i-1)*i%MOD;
        finv.at(i) = finv.at(i-1)*inv.at(i)%MOD;
    }
    for(i = 1;i <= max_number;++i){
        nCk.at(i) = fac.at(max_number)*finv.at(i)%MOD*finv.at(max_number-i)%MOD;
    }
    ll ans = 0;
    for(i = 0;i <= n;++i){
        ll num = k - a*i;
        if(num < 0) break;
        else{
            if(num%b == 0 && num/b <= n){
                ans += nCk[i]*nCk[num/b]%MOD;
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;

    return 0;
}