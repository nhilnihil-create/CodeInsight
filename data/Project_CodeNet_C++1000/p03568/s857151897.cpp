#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int tot = 1, cnt = 1;
  rep(i, n) {
    if (a[i] % 2 == 0) cnt *= 2;
    tot *= 3;
  }
  cout << tot - cnt << endl;
  return 0;
}