#include<bits/stdc++.h>

using namespace std;

void restore(int root, vector<vector<int>> &graph, vector<int> &tree){
  queue<int> q;
  q.push(root);
  
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(int child : graph[node]){
      tree[child]++;
      if(!tree[child]){
        tree[child] = node + 1;
        q.push(child);
      }
    }
  }
}

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<int> tree(N, 0);
  vector<vector<int>> graph(N);
  
  for(int j = 0; j < N - 1 + M; j++){
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    
    graph[A].push_back(B);
    tree[B]--;
  }
  
  int root;
  for(int i = 0; i < N; i++){
    if(!tree[i]){
      root = i;
      break;
    }
  }
  
  restore(root, graph, tree);
  
  for(int i = 0; i < N; i++){
    cout << tree[i] << endl;
  }
  
  return 0;
}