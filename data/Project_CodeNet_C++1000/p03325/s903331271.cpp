#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int cnt = 0;
  rep(i, n) while (a[i] % 2 == 0) {
    a[i] /= 2;
    cnt++;
  }
  cout << cnt << '\n';
  return 0;
}