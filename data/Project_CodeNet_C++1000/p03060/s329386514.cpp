#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> c(n);

  for (int i = 0; i < n * 2; i++)
  {
    if (i < n)
    {
      cin >> v[i];
    }
    else
    {
      cin >> c[i - n];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int buf = v[i] - c[i];
    if (buf > 0)
    {
      ans += buf;
    }
  }
  cout << ans << endl;
}
