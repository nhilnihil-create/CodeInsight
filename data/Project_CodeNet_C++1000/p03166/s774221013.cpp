#include <bits/stdc++.h>
using namespace std;

#define pb(a) push_back(a)
#define vi vector<int>
#define loop(i, n) for(int i=1;i<=n;i++)
#define loop0(i, n) for(int i=0;i<n;i++)
#define in(i) scanf("%d", &i);
#define out(i) printf("%d", i)

int n, ans, m, u, v, visited[100001], dp[100001];
vi adjacencyList[100001];
void dfs(int i)
{
  visited[i]=1;
  for(int elem:adjacencyList[i])
  {
    if(!visited[elem])
      dfs(elem);
    dp[i]=max(dp[elem]+1, dp[i]);
    ans=max(ans, dp[i]);
  }
}
void solve(int i)
{
  for(int i=1;i<=n;i++)
    if(!visited[i])
      dfs(i);
}
int main()
{
  in(n);
  in(m);
  loop(i, m)
  {
    in(u);
    in(v);
    adjacencyList[u].pb(v);
  }
  solve(1);
  sort(begin(dp), end(dp));
  cout<<ans<<"\n";
}

