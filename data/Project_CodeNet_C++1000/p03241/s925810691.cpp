#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int rtm = sqrt(m), mx = 1;
  for (int i = 1; i <= rtm; i++) {
    if (m % i == 0) {
      int g = i;
      if (m / g >= n)
        mx = max(mx, g);
      g = m / i;
      if (m / g >= n)
        mx = max(mx, g);
    }
  }
  cout << mx;
  return 0;
}