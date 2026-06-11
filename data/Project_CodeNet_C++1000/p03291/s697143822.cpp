#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using  namespace std;
typedef long long ll;
#define MOD 1000000007

int main() {
  string S;
  cin >> S;
  int n = S.length();
  int A[n] = {}; int B[n] = {}; int C[n] = {}; int D[n] = {};
  rep(i, n) {
    if (S[i] == 'A') ++A[i];
    else if (S[i] == 'B') ++B[i];
    else if (S[i] == 'C') ++C[i];
    else {
      ++A[i]; ++B[i]; ++C[i]; ++D[i];
    }
  }

  int Suml[n] = {};
  int Sumr[n] = {};
  Suml[0] = D[0]; Sumr[n-1] = D[n-1];
  for (int i = 1; i < n; ++i) Suml[i] = Suml[i-1] + D[i];
  for (int i = n-2; i >= 0; --i) Sumr[i] = Sumr[i+1] + D[i];
  ll Pow[Sumr[0] + 1] = {1};
  for (int i = 1; i <= Sumr[0]; ++i) Pow[i] = Pow[i-1] * 3 % MOD;
  
  ll L[n], R[n];
  L[0] = A[0]; R[n-1] = C[n-1];
  for (int i = 1; i < n; ++i) {
    L[i] = L[i-1];
    if (D[i]) L[i] *= 3;
    if (A[i]) L[i] += Pow[Suml[i-1]];
    L[i] %= MOD;
  }
  for (int i = n-2; i >= 0; --i) {
    R[i] = R[i+1];
    if (D[i]) R[i] *= 3;
    if (C[i]) R[i] += Pow[Sumr[i+1]];
    R[i] %= MOD;
  }
  
  ll ans = 0;
  for (int i = 1; i < n-1; ++i) {
    if (B[i]) {
      ans += L[i-1] * R[i+1];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}