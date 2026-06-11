#include <bits/stdc++.h>
#define ll long long
using namespace std;
int M = 1e9+7;
/*

dp on trees : 
dp[currnode][color] = number of ways of coloring currnode as color 0->black,1->white
f(currnode,last) = a function that sets dp[currnode][0] & dp[currnode][1],last is used to not loop for the parent node

dp[cur][0] = prod(dp[j][1] j = adjacent nodes to cur node)
dp[cur][1] = prod(dp[j][0] + dp[j][1])
every parent depends on the values of their children so leaf nodes should be filled first.dp[leaf][0]= dp[leaf][1] = 1

ans is dp[1][0]+dp[1][1] 1->root node;


*/

void f(int currnode,int parent,vector<vector<ll>> &dp,vector<vector<int>> &a){
  dp[currnode][0] = 1;
  dp[currnode][1] = 1;
  for(int x : a[currnode])
  {
    if(x == parent) continue;
    f(x,currnode,dp,a);
    dp[currnode][0] = (dp[currnode][0]*dp[x][1])%M;
    dp[currnode][1] = (dp[currnode][1]*(dp[x][1] + dp[x][0])%M);
  }
} 


int main() {
  int n;
  cin>>n;
  vector< vector<int> > a(n+1,vector<int>() );
  int x,y;
  for(int i=0;i<n-1;i++)
  {
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  vector<vector<ll>> dp(n+1,vector<ll>(2));
  f(1,-1,dp,a);
  cout<<(dp[1][1] + dp[1][0])%M;
  return 0;
}
