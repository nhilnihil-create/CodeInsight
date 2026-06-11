#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  int ans = 0;
  int a;
  rep(i, N) {
    cin >> a;
    ans += a;
  }
  cout << ans - N << endl;
  return 0;
}