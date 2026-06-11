#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int n, d, x;
  cin >> n >> d >> x;
  int cnt = x;
  rep(i, n) {
    int a;
    cin >> a;
    cnt += 1 + (d - 1) / a;
  }
  cout << cnt << endl;
  return 0;
}
