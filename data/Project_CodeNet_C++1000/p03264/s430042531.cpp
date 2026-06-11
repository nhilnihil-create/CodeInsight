#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int k;
  cin >> k;

  int ans = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = i + 1; j <= k; j++) {
      if(i % 2 != j % 2) ans++;
    }
  }
  cout << ans << '\n';
}