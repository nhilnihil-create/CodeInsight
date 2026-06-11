#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

// constexpr int INF = 1e9;
constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }
  return gcd(b, a%b);
}
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
  }
  vector<ll> G(N+1), RG(N+1);
  G[0] = A[0];
  FOR(i, 1, N){
    G[i] = gcd(A[i], G[i-1]);
  }
  RG[N-1] = A[N-1];
  REPR(i, N-2){
    RG[i] = gcd(A[i], RG[i+1]);
  }
  ll ans = max(G[N-2], RG[1]);
  FOR(i, 1, N-1){
    ans = max(ans, gcd(G[i-1], RG[i+1]));
  }
  cout << ans << endl;

  return 0;
}
