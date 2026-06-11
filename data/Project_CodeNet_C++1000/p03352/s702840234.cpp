#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 1010;

int main(void) {
  int X;
  cin >> X;

  vector<int> v(MAX_N, 0);
  v[1] = 1;
  for (int i = 2; i < MAX_N; ++i) {
    int num = i;
    while (num * i < MAX_N) {
      num *= i;
      v[num] = 1;
    }
  }

  int ans = 1;
  for (int i = X; X > 0; --i) {
    if (v[i]) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;
  
  return 0;
}