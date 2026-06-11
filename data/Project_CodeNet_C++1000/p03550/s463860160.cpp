#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;


int n,z,w;
vector<int> a(2010,0);
vector<int> dp(2010,-1);		//dp[i] x ga i get   score

int dfs(int k){
  if(dp[k]!=-1){ return dp[k]; }
  int ret=abs(a[k]-a[n-1]);
  
  if(k==n-1){ ret=abs(a[k]-w); return dp[k]=ret; }
  if(k==n-2){ ret=abs(a[k]-a[k+1]); return dp[k]=ret; }
  for(int i=k+1; i<n; i++){
    ret = min(ret,dfs(i));
  }  
  return dp[k]=ret;
}

int main(){
  cin >> n >> z >> w;
  rep(i,n){ cin >> a[i]; }
  int ans = dfs(0);
  rep(i,n){ ans = max(ans,dp[i]); }  
  cout << ans << endl;
  return 0;
}
