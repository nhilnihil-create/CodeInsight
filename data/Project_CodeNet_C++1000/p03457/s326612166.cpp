#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, N;
  cin >> N;
  int t[100001], x[100001], y[100001], z[100001];
  for (int i = 0; i < N; i++) cin >> t[i+1] >> x[i+1] >> y[i+1];
  t[0] = 0; x[0] = 0; y[0] = 0;

  for (int i = 0; i <= N; i++) z[i] = x[i] + y[i];
  for (int i = 0; i< N; i++) {
    a = abs(z[i+1] - z[i]);
    b = t[i+1] - t[i];
    if (b % 2 != a % 2 || a > b) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}