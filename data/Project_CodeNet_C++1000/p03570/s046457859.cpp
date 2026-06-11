#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=1e9;
const long long LINF=1e18;
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
int dp[200005],dp2[70000000],two[27];

//main
signed main(){
  string s;cin>>s; int N=s.size();
  two[0]=1;for(int i=1;i<26;i++)two[i]=two[i-1]*2;
  for(int i=0;i<N;i++)dp[i+1]=dp[i]^two[s[i]-'a'];//dp[i]^dp[j]のbitがちょうど1つの時、s[i]~s[j-1]が回文に出来る
  for(int i=1;i<70000000;i++)dp2[i]=INF;//dp2[i]:dp[j]=iを満たすjの中で[0,j)での最小値
  for(int i=0;i<N;i++){
    int res=INF;
    for(int j=0;j<27;j++)res=min(res,dp2[dp[i+1]^two[j]]);
    dp2[dp[i+1]]=min(dp2[dp[i+1]],res+1);
  }
  fin(max(dp2[dp[N]],1));
}
