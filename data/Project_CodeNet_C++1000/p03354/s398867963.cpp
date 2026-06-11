#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

struct unionfind{
  vector<int> par;
  unionfind(int n):par(n,-1){}
  void init(int n){par.assign(n,-1);}
  int root(int x){
    if(par[x]<0) return x;
    else return par[x]=root(par[x]);
  }
  bool issame(int x,int y){
    return root(x)==root(y);
  }
  bool merge(int x,int y){
    x=root(x); y=root(y);
    if(x==y) return false;
    if(par[x]>par[y]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
    return true;
  }
  int size(int x){
    return -par[root(x)];
  }
};

int main(){
  int n,m; cin >> n >> m;
  unionfind uf(n);
  vector<int> p(n);
  rep(i,n){
    cin >> p[i];
    p[i]--;
  }
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    uf.merge(a,b);
  }
  map<int,int> mp;
  rep(i,n){
    mp[p[i]]=i;
  }
  int ans=0;
  rep(i,n){
    if(uf.issame(mp[i],i)) ans++;
  }
  cout << ans << endl;
}