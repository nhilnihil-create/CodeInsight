#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

struct UnionFind {  
  vector<int> par,sizes;                     // par[i]:iの親の番号(ex)par[3]=2 : 3の親が2
  UnionFind(int n) : par(n),sizes(n,1)  {    //最初は全てが根であるとして初期化
    for(int i=0; i<n; i++){ par[i]=i; }  
  }
  int root(int x) {                       //xが属する木の根を再帰で得る:root(x)={xの木の根}
    if(par[x]==x){ return x; }
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) {                 // xとyの木を併合
    int rx = root(x);                        //xの根をrx
    int ry = root(y);                        //yの根をry
    if(rx == ry){ return; }                  //xとyの根が同じ(=同じ木にある)時はそのまま
    if(sizes[rx]<sizes[ry]){ swap(rx, ry); } //xの木をおおきくする
    par[ry] = rx; 
    sizes[rx] += sizes[ry];                  //sizes[ry]はもう使わない
  }
  bool check(int x, int y) {                 // x,yが属する木が同じならtrueを返す
    return root(x) == root(y);
  }
  int size(int x){                           //xが含まれる木の大きさを返す
    return sizes[root(x)];
  }
};

int main(){
  ll n,m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());

  vector<ll> cnt(m,n*(n-1)/2);
  UnionFind uf(n);
  rep(i,m-1){
    cnt[m-2-i] = cnt[m-1-i];
    if(!uf.check(a[i],b[i])){
      cnt[m-2-i] -= (ll)uf.size(a[i]) * (ll)uf.size(b[i]);
    }
    uf.unite(a[i],b[i]);
  }
  for(auto ans:cnt){
    cout << ans << endl;
  }
  return 0;
}