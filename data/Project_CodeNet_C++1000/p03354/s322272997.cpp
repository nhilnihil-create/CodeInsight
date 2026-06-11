#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, M; cin >> N >> M;
  vector<int> v (N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
    v[i]--;
  }
  vector<vector<int>> adj (N, vector<int> ());
  for(int i = 0; i < M; i++){
    int a, b; cin >> a >> b; a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> components (N, -1);
  int c = -1;
  for(int i = 0; i < N; i++){
    if(components[i] == -1){
      c++;
      queue<int> q;
      q.push(i);
      while(!q.empty()){
        int curr = q.front(); q.pop();
        if(components[curr] != -1) continue;
        components[curr] = c;
        for(int j = 0; j < adj[curr].size(); j++){
          q.push(adj[curr][j]);
        }
      }
    }
  }
  int res = 0;
  for(int i = 0; i < N; i++){
    if(components[i] == components[v[i]]){
      res++;
    }
  }
  cout << res << endl;
}
