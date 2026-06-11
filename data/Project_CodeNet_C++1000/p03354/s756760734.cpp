#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> r;
 
    UnionFind(int N) {
        r = vector<int>(N, -1);
    }
 
    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }
 
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }
 
    bool same(int x, int y) { 
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
 
 
int main() {
    int N,M;
    int ans = -1;
    int sum = 0;
    cin >> N >> M;
    vector<int> vec(N);
    UnionFind UF(N);
    for(int i=0;i<N;++i){
      cin >> vec.at(i);
    }

    for(int i=0;i<M;++i){
      int x,y; cin >> x >> y;
      x--; y--;
      UF.unite(x,y);
    }
while(sum > ans){
    ans = sum;
    sum = 0;
    for(int i=0;i<N;++i){
      if(UF.same(vec.at(i)-1,i)){
        swap(vec.at(vec.at(i)-1),vec.at(i));
      }
    }
    for(int i=0;i<N;++i){
      if(vec.at(i) == i+1) sum++;
    }
  }
    cout << ans << endl;
    return 0;
}