#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const string M_INF="-";

int n,m,cost[]={0,2,5,5,4,5,6,3,7,6};
string dp[10010];

void chmax(string &s, string t){
  if(s.size()<t.size())s=t;
  if(s.size()==t.size())if(s<t)s=t;
}

int main(){
  cin>>n>>m;
  vector<int>a(m);
  rep(i,m)cin>>a[i];
  
  rep(i,10010)dp[i]=M_INF;
  dp[0]="";
  for(int i=0; i<=n; ++i){
    if(dp[i]==M_INF)continue;
    rep(j,m){
      chmax(dp[i+cost[a[j]]],dp[i]+char(a[j]+'0'));
    }
  }
  cout<<dp[n]<<endl;
}