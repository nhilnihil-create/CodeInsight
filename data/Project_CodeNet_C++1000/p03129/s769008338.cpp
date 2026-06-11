#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;

  if (N >= 2 * K - 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}