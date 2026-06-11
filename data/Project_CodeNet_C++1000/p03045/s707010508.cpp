#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct unionfind{
  int par[100010]; // 親ノード  必要に応じて要素数を変えよう
  int rank[100010]; // ランク　必要に応じて要素数を変えよう
  unionfind(int n){
    init(n);
  }
  void init(int n){
    for(int i=0;i<=n;i++){
      par[i]=i;
      rank[i]=1;
    }
  }
  int root(int x) {
    if (par[x] == x) {
      return x;
    }
    else {
      return par[x] = root(par[x]);
    }
  }
  int size(int x){
    return rank[root(x)];
  }
  bool same(int x,int y) {
    return root(x) == root(y);
  }
  void unite(int x,int y) {
    x=root(x);
    y=root(y);
    if(x==y){
      return;
    }
    if(rank[x]<rank[y]){
      swap(x,y);
    }
    rank[x]=rank[x]+rank[y];
    par[y]=x;
  }
};
int main(){
  int n,m;
  cin >> n >> m;
  unionfind tree(n);
  int i;
  for(i=0;i<m;i++){
    int x,y,z;
    cin >> x >> y >> z;
    x--,y--;
    tree.unite(x,y);
  }
  int ans=0;
  vector<int> g(100010,0);
  for(i=0;i<n;i++){
    if(g[tree.root(i)]==0){
      ans++,g[tree.root(i)]=1;
    }
  }
  cout << ans << endl;
}