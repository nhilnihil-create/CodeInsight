//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;
const ll nmax = 1e9 + 7;
const ll mod = 998244353;
const long long INF = 1e18;
const double PI = 2 * asin(1);

int main(){
  int N; cin >> N;
  vector <int> graph[N];
  for (int i = 0; i < N - 1; i++){
    int A, B; cin >> A >> B;
    A--; B--;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }

  vector <int> dist(N);
  vector <bool> visited(N);

  queue <int> que;
  que.push(0); visited[0] = true;
  while (!que.empty()){
    int Q = que.front(); que.pop();
    for (int i = 0; i < graph[Q].size(); i++){
      int next = graph[Q][i];
      if (visited[next] == false){
        visited[next] = true;
        que.push(next);
        dist[next] = dist[Q] + 1;
      }
    }
  }

  int M = 0, edge = 0;
  for (int i = 0; i < N; i++){
    if (M < dist[i]){
      M = dist[i]; edge = i;
    }
  }
  
  fill(visited.begin(), visited.end(), false);
  fill(dist.begin(), dist.end(), 0);

  que.push(edge); visited[edge] = true;
  int R = 0;
  while (!que.empty()){
    int Q = que.front(); que.pop();
    for (int i = 0; i < graph[Q].size(); i++){
      int next = graph[Q][i];
      if (visited[next] == false){
        visited[next] = true;
        que.push(next);
        dist[next] = dist[Q] + 1;
        R = dist[next] + 1;
      }
    }
  }

  if (R % 3 == 2){
    cout << "Second" << endl;
  }else{
    cout << "First" << endl;
  }
  
  return 0;
}
