#include <iostream>

#define MOD 998244353
#define N_MAX 300002

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll inv[N_MAX],fac[N_MAX],finv[N_MAX];

void init(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        fac[i]=fac[i-1]*(ll) i%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

ll inv_(ll n){
    if(n == 1) return 1;
    else return MOD-inv_(MOD%n)*(MOD/n)%MOD;
}

ll comb(ll n, ll r){
  ll ans;
  if(n < r){
      ans = 0;
  }else{
      ans = (fac[n]*finv[r])%MOD;
      ans = (ans*finv[n-r])%MOD;
      ans = (ans+MOD)%MOD;
  }
  return ans;
}

int main(){
    init();
    ll N, A, B, K;
    cin >> N >> A >> B >> K;
    ll ans = 0;
    for(ll i = 0; i <= N; i++){
        if((K-i*A)%B == 0){
            ll j = (K-i*A)/B;
            if(j < 0) continue;
            ans += (comb(N, i)*comb(N, j))%MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}