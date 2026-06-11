#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
const int INF=1e9+7;
int main(){
  string s;cin>>s;
  
  vvll dp(s.size()+1,vll(4));
  dp[s.size()][3]=1;
  for(int j=s.size()-1;j>=0;j--){
    dp[j][3]=(s[j]=='?')?3*dp[j+1][3]:dp[j+1][3];
    dp[j][3]%=INF;
  }
  for(int i=2;i>=0;i--){
    dp[s.size()][i]=0;
    for(int j=s.size()-1;j>=0;j--){
      dp[j][i]=(s[j]=='?')?3*dp[j+1][i]:dp[j+1][i];
      if(s[j]=='?'||s[j]=='A'+i){dp[j][i]+=dp[j+1][i+1];}
      dp[j][i]%=INF;
    }
  }
  cout<<dp[0][0]%INF<<endl;
}