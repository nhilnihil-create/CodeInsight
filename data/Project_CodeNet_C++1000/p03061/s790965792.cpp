#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n), bef(n), back(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];

    if (i == 0) bef[i] = A[i];
    else bef[i] = gcd(A[i], bef[i - 1]);
  }

  back[n - 1] = A[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    back[i] = gcd(A[i], back[i + 1]);
  }

  int ans = max(bef[n - 2], back[1]);

  for (int i = 1; i < n - 1; i++) {
    ans = max(ans, gcd(bef[i - 1], back[i + 1]));
  }
  cout << ans << endl;

  return 0;
}