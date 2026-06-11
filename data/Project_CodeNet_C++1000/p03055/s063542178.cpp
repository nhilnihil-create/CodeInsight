#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
int main(){
  int N;
  cin >> N;
  vector<vector<int>> E(N);
  for (int i = 0; i < N - 1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<int> d(N, INF);
  d[0] = 0;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (d[w] == INF){
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
  }
  int s = 0;
  for (int i = 0; i < N; i++){
    if (d[i] > d[s]){
      s = i;
    }
  }
  vector<int> d2(N, INF);
  d2[s] = 0;
  queue<int> Q2;
  Q2.push(s);
  while (!Q2.empty()){
    int v = Q2.front();
    Q2.pop();
    for (int w : E[v]){
      if (d2[w] == INF){
        d2[w] = d2[v] + 1;
        Q2.push(w);
      }
    }
  }
  int t = 0;
  for (int i = 0; i < N; i++){
    if (d2[i] > d2[t]){
      t = i;
    }
  }
  if (d2[t] % 3 == 1){
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
}