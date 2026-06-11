#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

// aのn乗
ll modpow(ll a, ll n){
  ll r = 1;
  while (n) {
    r = r * ( (n%2)?a:1 ) %MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return r;
}

ll sum_inv[101010];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  sum_inv[0]=0;
  for(int i=1;i<101000;i++){
    sum_inv[i]=sum_inv[i-1];
    (sum_inv[i]+=modpow(i+1,MOD-2))%=MOD;
  }
  int N; cin>>N;
  ll sum=0;
  rep(i,N){
    ll a; cin>>a;
    sum+=a*sum_inv[i]%MOD;
    sum+=a*sum_inv[N-1-i]%MOD;
    sum+=a;
    sum%=MOD;
  }
  rep(i,N) (sum*=(i+1))%=MOD;
  cout<<sum<<endl;
  return 0;
}
