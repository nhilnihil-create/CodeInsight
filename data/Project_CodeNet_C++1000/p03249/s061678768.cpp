#include <bits/stdc++.h>

using namespace std;

long long dfs(int nd, vector<long long> &vis, vector<vector<int>> &adjList)
{
  vis[nd] += 1;
  long long ans = 0;
  for(int cd : adjList[nd])
  {
    if(!vis[cd])
    {
      ans += dfs(cd, vis, adjList);
      vis[nd] += vis[cd];
    }
  }
  ans += vis[nd] - 1;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<pair<long long, int>> d(n);
  vector<long long> sz(n, n);
  for(int i = 0; i < n; i++)
  {
    cin >> d[i].first;
    d[i].second = i + 1;
  }
  sort(d.begin(), d.end());
  vector<pair<int, int>> ans;
  vector<vector<int>> adjList(n + 1);
  for(int i = n - 1; i > 0; i--)
  {
    long long dval = d[i].first + (n - sz[i] + 1) - (sz[i] - 1);
    int pr = lower_bound(d.begin(), d.end(), make_pair(dval, 0)) - d.begin();
    if(pr >= i || d[pr].first != dval)
    {
      cout << "-1" << endl;
      return 0;
    }
    ans.push_back({d[i].second, d[pr].second});
    adjList[d[i].second].push_back(d[pr].second);
    adjList[d[pr].second].push_back(d[i].second);
    sz[pr] -= (n - sz[i] + 1);
  }
  vector<long long> vis(n + 1, 0);
  long long ver = dfs(d[0].second, vis, adjList);
  if(d[0].first != ver)
  {
    cout << "-1" << endl;
    return 0;
  }
  for(int i = 0; i < n - 1; i++)
  {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
