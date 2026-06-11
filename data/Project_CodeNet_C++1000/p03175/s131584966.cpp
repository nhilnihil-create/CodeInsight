/*
  Author: @yash_31
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#define ll long long int
#define eb emplace_back
#define fatafat ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define ft first
#define sd second
#define mkpr make_pair
#define deb(x) std::cout<<#x<<":"<<x<<endl;
#define whole(x) (x).begin(),(x).end()
#define revwhole(x) (x).rbegin(),(x).rend()
#define endl "\n"
#define fbo find_by_order
#define ook order_of_key
#define init0(x) memset(x,0,sizeof(x));

using namespace std; 
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> gharKaSet;
 
const int maxlimit=2e5+2;
const ll inf=1e18;
//TTBDC

ll dp[100005][2];
// 0 -black
bool vis[100005];

void dfs(int s,vector<int> g[]){
  vis[s]=true;
  // leaf node
  if(g[s].size()==1 && s!=1){
    dp[s][0]=dp[s][1]=1;return;
  }
  for(int x:g[s]){
    if(!vis[x]){
      dfs(x,g);
      dp[s][0] = (dp[s][0]*dp[x][1])%MOD;
      dp[s][1] = (dp[s][1]*(dp[x][0]+dp[x][1])%MOD)%MOD;
    }
  }
}

int main()
{
  fatafat
  int n,u,v;
  cin>>n;
  if(n==1){cout<<2;return 0;}
  vector<int> gx[n+1];
  for(int i=0;i<n-1;i++){
    dp[i+1][0]=dp[i+1][1]=1;
    cin>>u>>v;
    gx[u].eb(v);
    gx[v].eb(u);
  }
  dp[n][0]=dp[n][1]=1;
  dfs(1,gx);
  ll ans = (dp[1][1]+dp[1][0])%MOD;
  cout<<ans;
  return 0;
}