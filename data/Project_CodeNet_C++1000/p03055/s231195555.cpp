#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Tree{
public:
  vector<vector<int>> adj;
  int size;
  Tree(int size): size(size) {
    adj = vector<vector<int>>(size);
  }
  friend istream& operator>>(istream& is, Tree& tree){
    for(int i = 0; i < tree.size - 1; i++){
      int a, b;
      is >> a >> b;
      a--; b--;
      tree.adj[a].push_back(b);
      tree.adj[b].push_back(a);
    }
    return is;
  }
  int diameter(){
    pair<int, int> farthest_from_0 = farthest_node(0);
    pair<int, int> diameter_node = farthest_node(farthest_from_0.first);
    return diameter_node.second;
  }
  pair<int, int> farthest_node(int from){
    // pair: node, distance
    vector<bool> visited(size, false);
    vector<int> distances(size);
    pair<int, int> ret = make_pair(from, 0);

    stack<int> st;
    st.push(from);
    visited[from] = true;
    distances[from] = 0;
    while(!st.empty()){
      int now = st.top();
      st.pop();
      if(distances[now] > ret.second){
        ret = make_pair(now, distances[now]);
      }
      for(auto next: adj[now]){
        if(!visited[next]){
          st.push(next);
          visited[next] = true;
          distances[next] = distances[now] + 1;
        }
      }
    }
    return ret;
  }
};


int main(){
  int N;
  cin >> N;
  auto tree = Tree(N);
  cin >> tree;

  int diam = tree.diameter();
  //cout << diam << endl;
  if(diam % 3 != 1){
    cout << "First" << endl;
  }else{
    cout << "Second" << endl;
  }
}
