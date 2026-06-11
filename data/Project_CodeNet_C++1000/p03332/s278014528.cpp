#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 998244353;

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}

int main() {
  ll N,A,B,K;
  cin >> N >> A >> B >> K;
  ll sum=0;
  fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
  for(int i=0;i<max(K/A,N);i++){
    ll x=K-A*i;
    if(x>=0 && x%B==0 && x/B<=N){
      sum+=((comb(N,i)%M)*(comb(N,x/B))%M)%M;
      sum=sum%M;
    }
  }
  cout << sum;
}