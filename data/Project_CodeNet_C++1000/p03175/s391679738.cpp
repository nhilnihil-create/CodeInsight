#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
const ll mod=1e9+7;
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
const ll N=1e6+8;
const ll INF=1e18;
ll add(ll a, ll b) {
	a += b;
	if(a >= mod) return a - mod;
	return a;
}

ll mul(ll a, ll b) {
	a *= b;
	if(a >= mod) return a % mod;
	return a;
}

vector<ll> v[N];
ll dp[N][2];
ll my_name(ll x,ll y,ll p){
  if(dp[x][p]!=-1)
  return dp[x][p];
  ll res=1;
  if(p==1){
    for(auto it:v[x]){
      if(it==y)
      continue;
      res=mul(res,my_name(it,x,0));
    }
  }
  else{
   ll res1=1,res2=1;
    for(auto it:v[x]){
      if(it==y)
      continue;
      res1=mul(res1,my_name(it,x,1));
      res2=mul(res2,my_name(it,x,0));
    }
    res=add(res1,res2);
  }
  return dp[x][p]=res;
}
int main (){
  IOS;
 ll n;
 cin>>n;
 ll a,b;
 for(ll i=1;i<=n-1;i++){
   cin>>a>>b;
   v[a].pb(b);
   v[b].pb(a);
 }
 memset(dp,-1,sizeof(dp));
 cout<<my_name(1,0,0);
}