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

int main(){
  kyopro;
  ll tate, yoko, kaisuu;
  cin >> tate >> yoko >> kaisuu;
  ll initx, inity;
  cin >> inity >> initx;
  string takahashi, aoki;
  cin >> takahashi >> aoki;
  ll l{1}, r{yoko}, u{1}, d{tate};
  ll lm{1}, rm{yoko}, um{1}, dm{tate};
  rem(i, kaisuu-1, -1){
    if(takahashi[i] == 'L') l++;
    else if(takahashi[i] == 'R') r--;
    else if(takahashi[i] == 'U') u++;
    else if(takahashi[i] == 'D') d--;
    // cout << l << r << u << d << rt;
    if(i == 0) break;
    if(aoki[i-1] == 'R' && l > 1 && l <= r) l--;
    else if(aoki[i-1] == 'L' && r < yoko && l <= r) r++;
    else if(aoki[i-1] == 'D' && u > 1 && u <= d) u--;
    else if(aoki[i-1] == 'U' && d < tate && u <= d) d++;
  }
  if(l <= initx && initx <= r && u <= inity && inity <= d) cout << "YES" << rt;
  else cout << "NO" << rt;
}