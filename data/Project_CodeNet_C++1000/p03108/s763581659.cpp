#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
typedef tuple<double,ll,ll>T;
#define PI 3.14159265358979
const ll MOD = 1e12 + 7;

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

const int MAX = 510000;
//この設定だとn<10^7が限界。maxの０を一個増やせば100msかかるが一桁増やせる。
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}



int main(){
  ll N,M;
  cin>>N>>M;
  init(N+1);
  vector<ll>A(M);
  vector<ll>B(M);
  vector<ll>ans(M);
  rep(i,M){cin>>A[i]>>B[i];}
  ll mem=N*(N-1ll)/2ll;
  rep(i,M){ans[i]=0ll;}
  rep(i,M){
  	ans[M-i-1ll]=mem;
  	if(!same(A[M-1-i],B[M-1-i])){
      ll a=size(A[M-1-i]);
      ll b=size(B[M-1-i]);
      ll c=a+b;
      mem+=(a*(a-1ll)/2ll);
      mem+=(b*(b-1ll)/2ll);
      mem-=(c*(c-1)/2);
      unite(A[M-1-i],B[M-1-i]);
    }
  }
  rep(i,M){cout<<ans[i]<<endl;}
}