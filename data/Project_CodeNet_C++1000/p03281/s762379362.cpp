#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int yakusu(int n) {
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) ret++;
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i+=2) {
    if (yakusu(i) == 8) ans++;
  }
  cout << ans << endl;
  return 0;
}