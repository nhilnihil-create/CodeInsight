#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
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
  int ans=0,n,m,a[55],b[55],i,j;
  cin >> n >> m;
  for(i=0;i<m;i++){
    cin >> a[i] >> b[i];
  }
  for(i=0;i<m;i++){
    unionfind tree(n+10);
    for(j=0;j<m;j++){
      if(i==j){
        continue;
      }
      tree.unite(a[j],b[j]);
    }
    if(!tree.same(a[i],b[i])){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}