#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  if (n == 2) {
    cout << max(A[0], A[1]) << endl;
    return 0;
  }
  vector<int> B(n);
  vector<int> C(n);
  B[0] = A[0];
  C[n-1] = A[n-1];
  rep(i, n-1) {
    B[i+1] = gcd(A[i+1], B[i]);
    C[n-2-i] = gcd(A[n-2-i], C[n-1-i]);
  }
  int ans = C[1];
  rep(i, n-2) {
    ans = max(ans, gcd(B[i], C[i+2]));
  }
  ans = max(ans, B[n-2]);
  cout << ans << endl;
  return 0;
}