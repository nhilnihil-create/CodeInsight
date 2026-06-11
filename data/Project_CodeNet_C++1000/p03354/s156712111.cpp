/*   _/                _/                 _/_/_/   _/
  _/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
   _/     _/    _/   _/     _/    _/  _/_/_/     _/
  _/     _/    _/   _/     _/    _/  _/    _/   _/
   _/_/   _/_/       _/_/   _/_/      _/_/     _/ */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=1e9+5;
const ll INF=1e18+5;
using P=pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int n,m,par[100005]={},ans=0,p[100005]={},x,y;
struct unionfind {
  vector<int> par;
  unionfind(int n) : par(n,-1) {}
  void init(int n) {par.assign(n,-1);}
  int find(int x) {
    if (par[x]<0) return x;
    else return par[x]=find(par[x]);
  }
  bool issame(int x,int y) {
    return find(x)==find(y);
  }
  bool unit(int x,int y) {
    x=find(x),y=find(y);
    if (x==y) return false;
    if (par[x]>par[y]) swap(x, y); 
    par[x]+=par[y];
    par[y]=x;
    return true;
  }
  int size(int x) {
    return -par[find(x)];
  }
};
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  unionfind uf(n);
  for(int i=0; i<n; i++) {
    cin >> p[i];
    p[i]--;
    par[i]=i;
  }
  while(m--) {
    cin >> x >> y;
    x--,y--;
    uf.unit(x,y);
  }
  for(int i=0; i<n; i++) {
    if(uf.find(i)==uf.find(p[i])) {
      ans++;
    }
  }
  cout << ans << "\n";
}