#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1ll<<59

int main(){
  ll i,j;
  ll n,a,b;
  cin>>n>>b>>a;
  ll p[n+1];
  for(i=0;i<n;i++) cin>>p[i];
  p[n]=n+1;
  vector<ll> dp(n+1,INF);

  dp[0]=0;
  for(i=1;i<=n;i++){
    ll tmp=0;
    for(j=i-1;j>=0;j--){
      if(p[j]>p[i]) tmp+=b;
      else {
        dp[i]=min(dp[i],dp[j]+tmp);
        tmp+=a;
      }
    }
    dp[i]=min(dp[i],tmp);
  }
  cout<<dp[n]<<endl;
  return 0;
}