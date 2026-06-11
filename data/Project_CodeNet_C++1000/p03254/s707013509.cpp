#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  sort(a.begin(), a.end());
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    x -= a.at(i);
    if (x < 0) {
      break;
    }
    cnt++;
    if (i == n - 1 && x > 0) {
      cnt--;
    }
  }

  cout << cnt << endl;
  return 0;
}