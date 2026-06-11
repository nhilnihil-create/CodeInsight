#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, int>Pair;
#define MAX 1e9
struct edge { int to, cost; };
typedef pair<int, int>P;

//union_find木テンプレ
//問いに応じて最大の頂点数を定めること
#define MAXN 100100
long int par[MAXN];//親番号
long int rank[MAXN];//木の深さ
long int siz[MAXN];//属する集団のサイズ
//初期化関数
void init(int n) {
    rep(i, n) { par[i] = i; ::rank[i] = 0; siz[i] = 1; }
}
//木の根を求める関数
int find(int x) {
    if (par[x] == x) { return x; }
    else { return par[x] = find(par[x]); }
}
//xとｙの集合を併合する関数
void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y)return;
    if (::rank[x] < ::rank[y]) {
        par[x] = y;
        siz[y] += siz[x];
    }
    else {
        par[y] = x;
        siz[x] += siz[y];
        if (::rank[x] == ::rank[y])::rank[x]++;
    }
}
//同じかどうかとサイズがいくらか。
bool same(int x, int y) { return find(x) == find(y); }
int size(int x) { return siz[find(x)]; }

int main(){
  int N,M;
  cin>>N>>M;
  init(N);
  rep(i,M){
    int x,y,z;
    cin>>x>>y>>z;
    x--;y--;
    unite(x,y);
  }
  set<int>S;
  int ans=0;
  rep(i,N){
    if(!S.count(find(i))){
      S.insert(find(i));ans++;
    }
  }
  cout<<ans;
}


