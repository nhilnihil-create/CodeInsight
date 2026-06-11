#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int n;
  cin >> n;
  ll a[n];
  ll min_diff = 999999999999999;
  ll where = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a,a+n);
  for (int i = 0; i < n-1; i++) {
    if (abs(a[n-1] - (2LL * a[i])) < min_diff) {
      min_diff = abs(a[n-1] - (2LL * a[i]));
      where = i;
    }
  }
  cout << a[n-1] << " " << a[where] << endl;
  return 0;
}