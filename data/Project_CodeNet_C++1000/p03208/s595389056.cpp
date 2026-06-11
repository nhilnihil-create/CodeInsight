#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  sort(all(h));
  int ans = 1e9;
  for (int i = 0; i <= n - k; i++) {
    ans = min(ans, abs(h[i] - h[i + k - 1]));
  }
  cout << ans << endl;
  return 0;
}