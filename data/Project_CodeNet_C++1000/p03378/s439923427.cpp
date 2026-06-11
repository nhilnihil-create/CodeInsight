#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> v(n + 1, 0);
  for (int i = 0; i < m; i++)
  {
    int a;
    cin >> a;
    v[a] = 1;
  }
  int a, b;
  a = b = 0;
  for (int i = x; i <= n; i++)
  {
    if (v[i] == 1)
    {
      a++;
    }
  }
  for (int i = x; i >= 0; i--)
  {
    if (v[i] == 1)
    {
      b++;
    }
  }
  int ans = min(a, b);
  cout << ans << endl;
}
