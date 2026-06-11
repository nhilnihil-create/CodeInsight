#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int gcd(int a, int b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
  }


  vector<int> L(N), R(N);
  rep(i, N - 1) {
    L[i + 1] = gcd(L[i], A[i]);
  }
  for (int i = N -1; i >= 1; --i) {
    R[i - 1] = gcd(R[i], A[i]);
  }

  int ans = 1;
  rep(i, N) {
    ans = max(ans, gcd(L[i], R[i]));
  }

  cout << ans << endl;
  
  return 0;
}