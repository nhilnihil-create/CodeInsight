
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1e18;


ll dp[405][405];
vector<ll> s(405);

ll dfs(int l, int r){
  if (dp[l][r]!=-1)return dp[l][r];
  ll now=INF;
  for(int i=l;i<=r-1;i++){
      now=min(now,dfs(l,i)+dfs(i+1,r));
  }
  dp[l][r]=now+s[r+1]-s[l];
//  cout<<dp[l][r]<<"l"<<l<<"r"<<r<<endl;
  return dp[l][r];
}


int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  s[0]=0;
  rep(i,n)s[i+1]=s[i]+a[i];

  rep(i,405)rep(j,405)dp[i][j]=-1;
rep(i,n)dp[i][i]=0;

cout<<dfs(0,n-1);



}
