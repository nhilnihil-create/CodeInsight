#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  char last = s[0];
  int sum[n + 1];
  sum[0] = sum[1] = 0;
  for (int i = 1; i < n; i++)
  {
    sum[i + 1] = sum[i];
    if (last == 'A' && s[i] == 'C')
      sum[i + 1]++;
    last = s[i];
  }
  int ans[q];
  rep(i, q)
  {
    int l, r;
    cin >> l >> r;
    ans[i] = sum[r] - sum[l];
  }
  rep(i, q) cout << ans[i] << endl;
}