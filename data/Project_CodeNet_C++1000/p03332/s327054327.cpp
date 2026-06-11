#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

typedef long long ll;
typedef vector <ll> v_ll;
typedef vector <vector <ll> > vv_ll;
typedef vector < pair <ll,ll> > vp_ll;
typedef pair <ll,ll> p_ll;

ll mod_inv(ll x,ll n){
  x%=n;
  if (x<0) x+=n;
  ll y = x,z = n-2;
  ll ret=1;
  while (z>0){
    if(z%2==1){
      ret*=y;
      ret%=n;
    }
    y*=y;
    y%=n;
    z/=2;
  }
  return ret;
}

ll N,A,B,K;
ll MOD;
int main(){
  MOD=998244353;
  cin >> N >> A >> B >> K;
  v_ll NCK(N+1,0);
  NCK[0]=1;
  for (ll i=1;i<=N;i++){
    NCK[i]=(NCK[i-1]*(N+1-i))%MOD;
    NCK[i]*=mod_inv(i,MOD);
    NCK[i]%=MOD;
  }
  /*
  for (ll i=0;i<=N;i++){
    cout << NCK[i] << endl;
  }
  */
  ll ans=0;
  ll a=0,b=0;
  for (ll i=0;i<=N;i++){
    if ( (K>=A*i) && (K-A*i)%B==0 && (K-A*i)/B<=N ){
      a=i;b=(K-A*i)/B;
      ans+=(NCK[a]*NCK[b])%MOD;
      ans%=MOD;
    }
  }
  cout << ans << endl;
}
