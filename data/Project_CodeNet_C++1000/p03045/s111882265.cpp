#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define per(i,s,n) for(int i=n-1;i>=s;i--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

struct UnionFind{
  vector<int> par;
  
  UnionFind(int n) : par(n){
    rep(i,n){
      par[i] = i;
    }
  }
//木を深くならないように調節
  int root(int x){
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  
  void unite(int x, int y){
    if(root(x) == root(y)) return;
    par[root(x)] = root(y);
  }
  
  bool same(int x, int y){
    return root(x) == root(y);
  }
  
  void update_par(){
  for(int i=0;i<par.size();i++){
    root(i);
  }
  }
  
  int count(){
    set<int> s;
    int a=0;
    for(int i=0;i<par.size();i++){
      if(s.find(par[i])!=s.end()) continue;
      s.insert(par[i]);
      a++;
    }
    return a;
  }
      
  
  
};

int main(){
  int n,m;
  cin>>n>>m;
  int x,y,z;
  
  UnionFind u(n);
  rep(i,m){
    cin>>x>>y>>z;
    x--;
    y--;
    u.unite(x,y);
  }
  u.update_par();
  
 // cout<<1<<endl;
  
  int h=u.count();
  
  cout<<h<<endl;
}
  
  
  