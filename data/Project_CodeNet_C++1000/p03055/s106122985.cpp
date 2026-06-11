#include <bits/stdc++.h>
#define rt "\n"
#define sp " "
#define test(n) cout << "test" << n << endl;
#define fixsp(n) fixed << setprecision(n)
#define defsp(n) defaultfloat << setprecision(n)
#define kyopro ios::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
#define iikae auto&
#define vector3D(K, N, M, DP) vector<vector<vector<ll>>> DP(K, vector<vector<ll>>(N, vector<ll>(M)));
#define vector4D(K, N, M, O, DP) vector<vector<vector<vector<ll>>>> DP(K, vector<vector<vector<ll>>>(N, vector<vector<ll>>(M, vector<ll>(O))));
#define zenbu(a) a.begin(), a.end()
#define rzenbu(a) a.rbegin(), a.rend()
#define rep(i, s, N) for(ll i{s}; i < N; i++)
#define rem(i, N, s) for(ll i{N}; i > s; i--)
using namespace std;using ll = long long;using ld = long double;using P = pair<ll,ll>;/* 最大公約数 */template<typename T> T gcd(T a, T b){return b != 0 ? gcd(b, a % b) : a;}/* UnionFind */template<typename T> struct UnionFind{vector<T> par;UnionFind(T n) : par(n, -1){}void init(T n){par.assign(n, -1);}T root(T x){if (par[x] < 0) return x;else return par[x] = root(par[x]);}bool issame(T x, T y){return root(x) == root(y);}bool merge(T x, T y){x = root(x); y = root(y);if(x == y) return false;if(par[x] > par[y]) swap(x, y);par[x] += par[y];par[y] = x;return true;}int size(int x) {return -par[root(x)];}};/* コンビネーション */template<typename T> ll combpm(T N_, T C_) {const int NUM_=400001;static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];if (fact[0]==0) {inv[1]=fact[0]=factr[0]=1;for (int i=2;i<=NUM_;++i) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%MOD, factr[i]=factr[i-1]*inv[i]%MOD;}if(C_<0 || C_>N_) return 0;return factr[C_]*fact[N_]%MOD*factr[N_-C_]%MOD;}
/* ここからコード開始 */

vector<vector<ll>> ab;
ll D{}, S{};

void distant(ll ko, ll oya, ll distance){
  D = max(distance, D);
  if(D == distance) S = ko;
  for(auto&& mago : ab[ko]){
    if(oya == mago) continue;
    distant(mago, ko, distance + 1);
  }
}

int main(){
  kyopro;
  ll N;
  cin >> N;
  ab.assign(N, vector<ll>(0));
  rep(i, 0, N-1){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    ab[a].push_back(b);
    ab[b].push_back(a);
  }
  distant(0, -1, 0);
  distant(S, -1, 0);
  if(D % 3 == 1) cout << "Second" << rt;
  else cout << "First" << rt;
}