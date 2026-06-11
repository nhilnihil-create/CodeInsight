#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  int ans = 0;
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  rep(i, n - 1) {
    x -= a[i];
    if (x < 0) break;
    ans++;
  }
  if (x == a[n - 1]) ans++;

  cout << ans << endl;
}