#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
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
  int n,m;
  cin >> n >> m;
  int a[m],b[m];
  rep(i,m)cin >> a[i] >> b[i];
  rep(i,m){
    a[i]--;
    b[i]--;
  }
  int cnt=0;
  rep(i,m){
    UnionFind k(n);
    rep(j,m){
      if(j==i)continue;
      k.unionSet(a[j],b[j]);
    }
    if(k.size(0)!=n)cnt++;
  }
  cout << cnt << endl;
}
