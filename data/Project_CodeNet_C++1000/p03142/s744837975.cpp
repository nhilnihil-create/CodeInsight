#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int N, M;
vector<int> A, B, isRoot;
vector<vector<int>> graph;
vector<int> ans, homon;
int root;

int main(){
  cin >> N >> M;
  A.resize(N+M-1), B.resize(N+M-1);
  graph.resize(N);
  isRoot.resize(N, 0);
  REP(i, N+M-1){
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
    graph[A[i]].push_back(B[i]);
    isRoot[B[i]]++;
  }
  REP(i, N){
    if(isRoot[i]==0){
      root = i;
      break;
    }
  }
  ans.resize(N, -1);
  ans[root] = 0;
  homon.resize(N, 0);
  
  queue<int> que;
  que.push(root);
  while(!que.empty()){
    int node = que.front();
    que.pop();
    REP(i, graph[node].size()){
      int nx = graph[node][i];
      homon[nx]++;
      if(homon[nx] == isRoot[nx]){
        que.push(nx);
        ans[nx] = node + 1;
      }
    }
  }

  REP(i, N){
    cout << ans[i] << endl;
  }
  return 0;
}
