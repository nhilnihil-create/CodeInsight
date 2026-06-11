#include <bits/stdc++.h>
using namespace std;

int solve()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q, ans = 0, count = 0;
  string s;
  cin >> q;
  vector<int> v(101010, 0);
  vector<int> vm(101011, 0);

  // エラトステネスのふるい
  int MAX = 101010;
  vector<int> is_prime(MAX, 1);
  is_prime[0] = 0;
  is_prime[1] = 0;
  for (int i = 2; i < MAX; ++i)
  {
    if (!is_prime[i])
      continue;
    for (int j = i * 2; j < MAX; j += i)
      is_prime[j] = 0;
  }

  for (int j = 0; j < 101010; j++)
  {
    if (is_prime[j] != 1 || is_prime[(j + 1) / 2] != 1 || j % 2 == 0)
    {
    }
    else
    {
      v[j]++;
    }
  }
  for (int j = 0; j <= 101010; j++)
  {
    vm[j + 1] = v[j] + vm[j];
  }

  for (int i = 0; i < q; i++)
  {
    int l, r;
    cin >> l >> r;
    ans = vm[r + 1] - vm[l];
    cout << ans << endl;
    count = 0;
  }
  return 0;
}
signed main()
{
  solve();
}