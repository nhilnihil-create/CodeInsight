#include <bits/stdc++.h> //library
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //for-loop (from 0)
#define reps(i,n) for(int i = 1; i <= (int)(n); i++) //for-loop (from 1)
#define all(x) (x).begin(),(x).end() //start-to-end iteration, mainly in upper_bound, lower_bound
#define SZ(x) ((int)(x).size()) //unsigned to signed

using namespace std;
using ll = long long; //long long
ll M = 1000000000 + 7;
const ll INF = 1LL << 60;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; } //compare a,b and replace by greater
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; } //compare a,b and replace by smaller
ll qp(int a, ll b) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; } //power
ll qp(int a, ll b, ll Mod) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a%Mod; a = 1ll * a*a%Mod; } while (b >>= 1); return ans; } //power(mod)
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; } //gcd
int dx[4] = { 1,0,-1,0 }; //path
int dy[4] = { 0,1,0,-1 }; //path
ll RS(ll N, ll P) { if (P == 0)return 1; else if (P % 2 == 0) { ll sq = RS(N, P / 2); return sq*sq; } else { return N*RS(N, P - 1); } } //power(repeat-square,fast)
ll nPr(ll n, ll r) { ll ans = 1; rep(i, r) { ans = ans * (n - i); } return ans; } //permutation
ll nCr(ll n, ll r) { ll bunbo = 1; ll bunshi = 1; rep(i, r) { bunbo = bunbo * (i + 1); bunshi = bunshi * (n - i); } return bunshi / bunbo; } //combination
ll RS(ll N, ll P, ll Mod) { if (P == 0)return 1; else if (P % 2 == 0) { ll sq = RS(N, P / 2, Mod); return sq*sq%Mod; } else { return N*RS(N, P - 1, Mod) % Mod; } } //power(mod)(repeat-square,fast)
ll nPr(ll n, ll r, ll Mod) { ll ans = 1; rep(i, r) { ans = ans * (n - i) % Mod; } return ans; } //permutation
ll nCr(ll n, ll r, ll Mod) { ll bunbo = 1; ll bunshi = 1; rep(i, r) { bunbo = bunbo * (i + 1) % Mod; bunshi = bunshi * (n - i) % Mod; } return bunshi * RS(bunbo, Mod - 2, Mod) % Mod; } //combination

int N,K;

int main(void) {
  cin >> N >> K;
  cout << ceil((double)(N-1)/(double)(K-1)) << "\n";
  return 0;
}
