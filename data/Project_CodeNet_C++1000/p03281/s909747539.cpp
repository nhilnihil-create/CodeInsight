#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> yakusu(201, 0);
  for (int i = 1; i <= 200; i++) {
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) yakusu[i]++;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i += 2) {
    if (yakusu[i] == 8) ans++;
  }

  cout << ans << endl;
  return 0;
}
