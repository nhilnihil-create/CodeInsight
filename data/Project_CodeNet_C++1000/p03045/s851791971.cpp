#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
// union find
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
  cout << setprecision(10);
  int N,M; cin >> N >> M;
  UnionFind tree(N);

  for(int i = 0; i < M; i++){
    int x,y,z; cin >> x >> y >> z;
    x--; y--;

    tree.unionSet(x,y);
  }

  map<int,int> m;
  for(int i = 0; i < N; i++){
    m[tree.root(i)]++;
  }
  cout << m.size() << endl;
}
