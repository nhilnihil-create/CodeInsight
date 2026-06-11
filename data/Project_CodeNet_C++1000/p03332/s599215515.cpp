#include <iostream>
typedef long long int ll;
using namespace std;
#define P 998244353
#define N_MAX 300000
ll fac[N_MAX+1];
ll inv[N_MAX+1];
ll finv[N_MAX+1];

ll comb(ll n, ll k){
    return (((fac[n]*finv[n-k])%P)*finv[k])%P;
}

void init(){
    fac[0] = finv[0] = fac[1] = finv[1] = inv[1] = 1;
    for(int i = 2; i <= N_MAX; i++){
        fac[i] = (fac[i-1]*i)%P;
        inv[i] = ((-(P/i)*inv[P%i])%P+P)%P;
        finv[i] = (finv[i-1]*inv[i])%P;
    }
}

int main(){
    init();
    ll N, A, B, K, ans =0;
    std::cin >> N >> A >> B >> K;
    for(ll i=0;i<N+1;i++){
      ll j = (K - A * i)/B;
      if((K-A*i)%B == 0 && j <= N && j >= 0){
        ans = (ans + (comb(N, i) * comb(N, j))%P)%P;
      }
    }
    std::cout << ans << '\n';
}
