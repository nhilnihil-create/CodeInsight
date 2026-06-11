#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 998244353;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}

int main(){
  ll N,A,B,K,ans=0;
  cin >> N >> A >> B >> K;
  if(K%gcd(A,B)!=0){
    cout << 0 << endl;
    return 0;
  }
  vec comb(N+1);
  comb.at(0)=1;
  rep(i,N){
    comb.at(i+1)=comb.at(i)*(N-i);
    comb.at(i+1)%=MOD;
    comb.at(i+1)*=modPow(i+1,MOD-2);
    comb.at(i+1)%=MOD;
  }
  rep(i,N+1){
    if(K<A*i){
      break;
    }
    if((K-A*i)%B==0&&(K-A*i)/B<=N){
      ans+=comb.at(i)*comb.at((K-A*i)/B);
      ans%=MOD;
    }
  }
  cout << ans << endl;
      
}