#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, p = 0;
  cin >> n;
  vector<int> A(n);
  int sum = 0;
  for (auto &a : A) {
    cin >> a;
    sum += abs(a-p);
    p = a;
  }
  sum += abs(A[n-1]);

  int res = 0;
  for (int i = 0; i < n; ++i) {
    res = 0;
    if (i > 0 && i < n-1) {
      res = sum - abs(A[i]-A[i-1]) - abs(A[i+1]-A[i]) + abs(A[i-1]-A[i+1]);
    } else if (i == 0) {
      res = sum - abs(A[0]) - abs(A[1]-A[0]) + abs(A[1]);
    } else if (i == n-1) {
      res = sum - abs(A[i]-A[i-1]) - abs(A[n-1]) + abs(A[n-2]);
    }
    cout << res << endl;
  }

  return 0;
}

