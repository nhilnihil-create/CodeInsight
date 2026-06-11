#pragma region
#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(x,arr) for(auto& x:arr)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define VPII vector<PII>
#define VPLL vector<PLL>
#define FI first 
#define SE second
#define ALL(x) (x).begin(), (x).end()
constexpr int INF=1<<30; constexpr ll LINF=1LL<<60; constexpr ll mod=1e9+7; constexpr int NIL = -1;
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
#pragma endregion
//-------------------
ll n;
ll A,B,C;
ll L[10];
ll dfs(ll cur, ll a, ll b, ll c) {
  if(cur == n) {
    ll now = abs(a-A) + abs(b-B) + abs(c-C) - 30;
    if(min(a, min(b,c)) > 0) return now;
    else return LINF;
  }
  ll k0 = dfs(cur+1, a,b,c);
  ll k1 = dfs(cur+1, a + L[cur], b, c) + 10;
  ll k2 = dfs(cur+1, a, b+L[cur], c) + 10;
  ll k3 = dfs(cur+1, a, b, c+L[cur]) + 10;
  return min(k0, min(k2, min(k1, k3)));
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false); //cout << fixed << setprecision(15);
  cin >> n >> A >> B >> C;
  FOR(i,0,n-1) {
    cin >> L[i];
  }
  cout << dfs(0, 0, 0, 0) << endl;

  return 0;
}
