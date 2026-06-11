#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  int A;
  int min_a = INT_MAX;
  int max_a = -INT_MAX;
  rep(i, N) {
    cin >> A;
    min_a = min(min_a, A);
    max_a = max(max_a, A);
  }

  cout << max_a - min_a << endl;
  return 0;
}