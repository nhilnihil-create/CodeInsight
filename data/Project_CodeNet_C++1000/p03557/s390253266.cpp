#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N), B(N), C(N);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  rep(i,N) cin >> C[i];

  // sort(all(A), greater<ll>());
  // sort(all(B), greater<ll>());
  // sort(all(C), greater<ll>());
  sort(all(A));
  sort(all(B));
  sort(all(C));
  ll ans = 0;
  ll j = 0;
  ll k = 0;
  vector<ll> dp(N+1);
  dp[0] = 0;
  rep(i, N) {
    while(B[j] < C[i] && j < N) {
      while(A[k] < B[j] && k < N) {
        k++;
      }
      dp[j+1] = dp[j] + k;
      j++;
    }
    // cerr << i <<" "<< j <<" "<< k <<" "<<  dp[j] << endl;
    ans += dp[j];
  }
  cout << ans << endl;
  return 0;
}
