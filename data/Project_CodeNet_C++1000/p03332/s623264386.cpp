#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
const ll MOD = 998244353;
const ll N = 555555;

//a^(p-2)=a^(-1) (mod p)
//(x^n)%mod
ll mod_pow(ll x,ll n,ll mod){
  if(n==0)return 1;
  ll res=mod_pow( x*x%mod , n/2 , mod );
  if( n & 1 )res = res*x%mod;
  return res;
}

ll fact[N];
ll infact[N];

void make_factorial(void){
  fact[0] = 1;
  for( ll i = 1 ; i < N ; i++ ){
    fact[i] = fact[i-1] * i;
    fact[i] %= MOD;
  }
  for( ll i = 0 ; i < N ; i++ ){
    infact[i] = mod_pow( fact[i] , MOD-2 , MOD );
  }
}

ll comb(ll a,ll b){
  if(a == 0 && b == 0)return 1;
  if(a < b || a < 0)return 0;
  ll tmp = infact[a-b]* infact[b] % MOD;
  return tmp * fact[a] % MOD; 
}

int main(){
  ll n,a,b,k;
  cin>>n>>a>>b>>k;
  
  if(k==0){
    cout<<1<<endl;
    return 0;
  }

  make_factorial();

  ll ans=0;
  for(ll i=0;i<=n;i++){
    if(k<a*i)continue;
    if((k-i*a)%b)continue;
    ll x=i;
    ll y=(k-i*a)/b;
    
    ans+=(comb(n,x)*comb(n,y))%MOD;
    ans%=MOD;
  }
  
  cout<<ans<<endl;
  return 0;
}
