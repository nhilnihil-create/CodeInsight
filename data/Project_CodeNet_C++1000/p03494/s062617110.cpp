#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int cnt = 0;
    while (a[i] % 2 == 0) {
      cnt++;
      a[i] /= 2;
    }
    ans = min(cnt, ans);
  }
  cout << ans << endl;
  return 0;
}