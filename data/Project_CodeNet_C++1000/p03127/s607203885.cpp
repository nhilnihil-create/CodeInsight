#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int min = *min_element(a.begin(), a.end());

  sort(a.begin(), a.end());

  ll ans = a[0];

  for (int i = 0; i < n; i++) {
    ans = gcd(ans, a[i]);
  }

  cout << ans << endl;
}