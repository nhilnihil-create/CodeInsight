#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll fac[100000+1],si[100000+1],a[100000],ans,n;

ll mpow(ll x,ll n){
    ll res = 1;
    while(n != 0){
        if(n&1) res = res*x % mod;
        x = x*x % mod;
        n = n >> 1; 
    }
    return res;
}
void calc_fac(){
   fac[0] = 1;
   si[0] = 0;
   for(int i = 0;i < 100000;i ++){
       fac[i+1] = fac[i]*(i+1) % mod;
       si[i+1] = (si[i]+mpow(i+1,mod-2)) % mod;
   }
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i ++){
        cin >> a[i];
    }
    calc_fac();
    for(int j = 0;j < n;j ++){
        ans += (si[n-j]+si[j+1]-1)%mod*a[j];
        ans %= mod;
    }
    ans *= fac[n];
    ans %= mod;
    cout << ans << endl;
}