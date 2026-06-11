#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
vector<int> adj[100000];
vector<int> adj_rev[100000];

int find_root(){
  for(int i = 0; i < N; i++){
    if(adj_rev[i].size() == 0){
      return i;
    }
  }
}

int main(){
  cin >> N >> M;
  for(int i = 0; i < N - 1 + M; i++){
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj_rev[b - 1].push_back(a - 1);
  }
  int root = find_root();

  int depth[100000] = {};
  for(int i = 0; i < N; i++){
    depth[i] = -1;
  }

  int parent_visited_count[100000] = {};
  stack<int> st;
  st.push(root);
  depth[root] = 0;
  while(!st.empty()){
    int now = st.top(); st.pop();

    if(parent_visited_count[now] < adj_rev[now].size()){
      continue;
    }

    for(int i = 0; i < adj[now].size(); i++){
      int next = adj[now][i];
      parent_visited_count[next]++;
      if(depth[next] < depth[now] + 1){
	depth[next] = depth[now] + 1;
	st.push(next);
      }
    }
  }

  for(int i = 0; i < N; i++){
    if(i == root){
      cout << 0 << endl;
    }else{
      for(int j = 0; j < adj_rev[i].size(); j++){
	if(depth[i] == depth[adj_rev[i][j]] + 1){
	  cout << adj_rev[i][j] + 1 << endl;
	}
      }
    }
  }
}

