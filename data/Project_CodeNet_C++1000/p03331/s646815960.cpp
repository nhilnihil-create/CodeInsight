#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 998244353;

int digit (int a) {
  int res = 0;
  while (a >= 10) {
    res += a % 10;
    a -= a % 10;
    a /= 10;
  }
  res += a;
  return res;
}

int main() {
  int N;
  cin >> N;
  int ans = 9999999;
  for (int i = 1; i <= N-1; i++) {
    int a = digit(i) + digit(N-i);
    ans = min(ans,a);
  }
  cout << ans << endl;
  return 0;
}