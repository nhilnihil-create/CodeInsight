#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res, n, c, silnia = 1;
const int mod = 1e9 + 7, maxn = 1e5 + 5;
ll p[maxn];
ll pref[maxn];
ll pot(ll a, ll b){
  ll res = 1;
  while (b){
    if (b&1)
      res = res*a%mod;
    b >>=1 ;
    a = a*a%mod;
  }

  return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        p[i] = pot(i, mod-2);
        pref[i] = (pref[i-1] + p[i])%mod;
    }
    for(int i=1; i<=n; i++){
        silnia = silnia * i % mod;
        cin >> c;
        res += c * (pref[i] + pref[n-i+1] - 1)%mod;
        res %= mod;
    }
    cout << res*silnia%mod;
}
