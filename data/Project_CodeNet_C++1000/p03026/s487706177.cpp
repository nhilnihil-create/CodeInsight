#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<vector<int>> graph(N);
  vector<int> d(N, 0);
  for(int i = 0; i < N - 1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  vector<int> c(N);
  for(int i = 0; i < N; i++) cin >> c[i];
  
  sort(c.rbegin(), c.rend());
  
  int M = 0;
  queue<int> q;
  d[0] = c[0];
  for(int post : graph[0]) if(!d[post]) q.push(post);
  for(int i = 1; i < N; i++){
    int cur = q.front();
    q.pop();
    M += (d[cur] = c[i]);
    for(int post : graph[cur]) if(!d[post]) q.push(post);
  }
  
  cout << M << endl;
  for(int i = 0; i < N - 1; i++) cout << d[i] << ' ';
  cout << d[N - 1] << endl;
  
  return 0;
}