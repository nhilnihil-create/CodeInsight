#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> a(n);
  range(i, 0, n) cin >> a[i];
  if(a[n - 1] != 2) {
    cout << -1;
    return 0;
  }
  a.pop_back();
  reverse(a.begin(), a.end());
  long long x = 2;
  long long y = 3;
  for(int i : a) {
    x = ((x + i - 1) / i) * i;
    y = (y / i) * i + i - 1;
    if(y < x) {
      cout << -1;
      return 0;
    }
  }
  cout << x << " " << y;
  return 0;
}
