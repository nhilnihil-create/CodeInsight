#include<bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int main(){
  int N,K;
  cin >> N >> K;
  vector<int> v(N);
  
  for(int i = 0; i < N; i++){
    cin >> v.at(i);
  }
  
  UnionFind tree(N);
  for(int i = 0; i < K; i++){
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    tmp1--;
    tmp2--;
    tree.unionSet(tmp1,tmp2);
  }
  
  int ans = 0;
  for(int i = 0; i < N; i++){
    if(tree.root(i) == tree.root(v.at(i)-1)){
      ans++;
    }
  }
  cout << ans << endl;
}

