#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int main()
{
  int n, m;
  cin >> n >> m;
  
  vector<int> p(n);
  rep(i, n) {cin >> p[i]; p[i]--;}
  
  vector<vector<int>> graph(n, vector<int>(0));
  rep(i, m)
  {
    int x, y;
    cin >> x >> y;
    x--; y--;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  rep(i, n)
  {
    sort(graph[i].begin(), graph[i].end());
    graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
    //for(int x : graph[i]) cout << x << " "; cout << endl;
  }
  
  vector<bool> visited(n, false);
  stack<int> stc;
  int res = 0;
  rep(i, n)
  {
    if(visited[i]) continue;
    stc.push(i);
    
    vector<int> key(0);
    set<int> val;
    
    while(stc.size())
    {
      int x = stc.top();
      stc.pop();
      visited[x] = true;
      key.emplace_back(x);
      val.insert(p[x]);
      
      for(int y : graph[x])
      {
        if(!visited[y])
          stc.push(y);
      }
    }
    sort(key.begin(), key.end());
    key.erase(unique(key.begin(), key.end()), key.end());
    
    for(int x : key)
    {
      if(val.find(x) != val.end()) res++;
    }
  }
  
  cout << res << endl;
  
  return 0;
}
  
  
  