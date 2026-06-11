#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846
const ll MAX = 1e5+10;
const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<ll> a[MAX];
ll dp[MAX][2];
ll visited[MAX];

void dfs(int node)
{
  visited[node]=1;
  for(int i=0;i<a[node].size();i++)
  {
    if(visited[a[node][i]]==1)
      continue;
   	dfs(a[node][i]);
    ll k = a[node][i];
    ll w = dp[k][0]+dp[k][1];
    ll b = dp[k][0];
    dp[node][0]=(dp[node][0]*w)%MOD;
    dp[node][1]=(dp[node][1]*b)%MOD;
  }
}

int main()
{
  ll n,i,j,k,l,p,q,x,y;
  cin >> n;
  for(i=0;i<n-1;i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  for(i=0;i<MAX;i++)
  {
    dp[i][0]=1;dp[i][1]=1;
  }
  dfs(1);
  p = dp[1][0]+dp[1][1];
  p = p%MOD;
  cout << p;
}

