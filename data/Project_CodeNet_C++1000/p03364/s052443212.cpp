#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int A = 0; A < n; ++A) {
    bool works = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int ni1 = (i + A) % n;
        int nj1 = j;
        int ni2 = i;
        int nj2 = (j + A) % n;
        if (a[ni1][nj1] != a[nj2][ni2]) {
          works = false;
          break;
        }
      }
      if (!works) break;
    }
    if (works) {
      ans += n;
    }
  }
  cout << ans << endl;
  return 0;
}
