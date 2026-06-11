#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, m, n) for (int i = m; i < n; ++i)
const int MOD = 1000000007;

int main() {
  int N, K;
  cin >> N >> K;
  cout << ((N+1)/2 >= K ? "YES" : "NO") << endl;
  return 0;
}
