//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n;cin>>n;
  vl c(n);
  rep(i,n)cin>>c[i];
  vl dp(n+1);
  rep(i,n+1)dp[i]=0;
  map<ll,ll>M;
  dp[0]=1;
  for(ll i=1;i<=n;i++){
    if(i!=1&&c[i-1]==c[i-2]){
      dp[i]=dp[i-1];
      continue;
    }
    dp[i]=M[c[i-1]]+dp[i-1];
    dp[i]%=MOD;
    M[c[i-1]]=dp[i];
  }
  //rep(i,n+1)cout<<dp[i]<<" ";
  cout<<dp[n]<<endl;
}
    