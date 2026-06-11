#include<bits/stdc++.h>

using namespace std;

void dfs(int src, vector<int>& dist, vector<vector<int>>& graph){
  stack<int> s;
  s.push(src);
  vector<bool> used(graph.size(), false);
  used[src] = true;
  
  while(s.size()){
    int node = s.top();
    s.pop();
    
    for(int next : graph[node]){
      if(used[next]) continue;
      
      dist[next] = dist[node] + 1;
      used[next] = true;
      s.push(next);
    }
  }
}

int main(){
  int N;
  cin >> N;
  
  vector<vector<int>> graph(N);
  for(int i = 0; i < N - 1; i++){
    int a, b;
    cin >> a >> b;
    --a; --b;
    
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  vector<int> dist(N, -1);
  dist[0] = 0;
  dfs(0, dist, graph);
  
  int furthest = -1;
  int max_dist = 0;
  for(int i = 0; i < N; i++){
    if(dist[i] >= max_dist){
      furthest = i;
      max_dist = dist[i];
    }
  }
  
  dist[furthest] = 0;
  dfs(furthest, dist, graph);
  
  max_dist = 0;
  for(int i = 0; i < N; i++) max_dist = max(dist[i], max_dist);
  
  puts(max_dist % 3 == 1 ? "Second" : "First");
  
  return 0;
}