#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, a;
  cin >> n;
  vector<int> A(n);
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    A[i-1] = a - i;
  }
  sort(A.begin(), A.end());
  int b = A[n/2];
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += abs(A[i]-b);
  }
  cout << res << endl;

  return 0;
}

