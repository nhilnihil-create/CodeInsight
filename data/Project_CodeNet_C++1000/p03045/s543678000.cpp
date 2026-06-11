#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)10000000000000000
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

int main() {
  int N,M;
  cin>>N>>M;
  init(N);
  rep(i,M){
    int x,y,z;
    cin>>x>>y>>z;
    x--;y--;
    unite(x,y);
  }
  set<int>st;
  int cnt=0;
  rep(i,N){
    int p=find(i);
    if(!st.count(p)){
      cnt++;
      st.insert(p);
    }
  }
  cout<<cnt;
}


