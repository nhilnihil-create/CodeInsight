#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main(void) {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
  }
 
  vector<ll> B(N);
  rep(i, N) {
    B[i] = A[i] - (i + 1);
  }
 
  sort(B.begin(), B.end());
 
  ll b = 0;
  if (N % 2 != 0) {
    b = B[N / 2];
  } else {
    b = (B[N / 2] + B[N / 2 - 1]) / 2;
  }
 
  ll ans = 0;
  rep(i, N) {
    ans += abs(B[i] - b);
  }
 
  cout << ans << endl;
  
  return 0;
}