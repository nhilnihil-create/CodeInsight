#include<bits/stdc++.h>
using namespace std;
struct unionFind{
  vector<int>par;

  unionFind(int n):par(n){
    for(int i=0;i<n;i++)par[i] = i;
  }

  int find(int x){
    if(par[x]==x)return x;
    else return par[x] = find(par[x]);
  }

  void unite(int x,int y){
    int xx = find(x);
    int yy = find(y);
    if(xx==yy)return;
    else{
      par[xx]=yy;
      return;
    }
  }

  bool same(int x,int y){
    int xx = find(x);
    int yy = find(y);
    return xx == yy;
  }

};

int main(){
  int n,m;
  cin >> n >> m;
  vector<int>p(n);
  int i;
  for(i=0;i<n;i++){
    cin >> p[i];
  }
  int x,y;
  unionFind unif(n+1);
  for(i=0;i<m;i++){
    cin >> x >> y;
    unif.unite(x,y);
  }
  int ans = 0;
  for(i=0;i<n;i++){
    if(unif.same(p[i],i+1))ans++;
  }
  cout << ans << endl;
}
