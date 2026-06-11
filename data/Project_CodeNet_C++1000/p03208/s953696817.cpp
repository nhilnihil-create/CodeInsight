#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n, k;
  cin >> n >> k;
  int a[n];
  rep(i, n) cin >> a[i];
  sort(a, a + n);
  int ans = 1000000005;
  rep2(i, 0, n - k + 1) ans = min(ans, a[i + k - 1] - a[i]);
  cout << ans << endl;

  return 0;
}