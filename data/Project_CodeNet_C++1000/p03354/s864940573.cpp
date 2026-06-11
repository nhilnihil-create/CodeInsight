#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<climits>
#define MOD 1000000007
typedef long long ll;
using namespace std;

struct UnionFind{
  vector<int> par;

  UnionFind(int N) : par(N){
    for(int i=0;i<N;i++) par[i] = i;
  }

  void init(int N){
    for(int i=0;i<N;i++) par[i] = i;
  }

  int root(int x){
    if(par[x] == x) return x;
    else return par[x] = root(par[x]);
  }

  void unite(int x, int y){
    int rx = root(x);
    int ry = root(y);
    if(rx == ry) return;
    par[rx] = ry;
  }

  bool same(int x, int y){
    return root(x) == root(y);
  }
};

int main(){
  int N,M; cin >> N >> M;
  int p[100005];
  // UnionFind x(N);
  UnionFind px(N+1);
  for(int i=1;i<=N;i++) cin >> p[i];

  for(int i=1;i<=M;i++){
    int a,b; cin >> a >> b;
    // x.unite(a,b);
    px.unite(p[a],p[b]);
  }

  int ans = 0;
  for(int i=1;i<=N;i++){
    if(px.same(i,p[i])) ans++;
  }
  cout << ans << endl;
  return 0;
}