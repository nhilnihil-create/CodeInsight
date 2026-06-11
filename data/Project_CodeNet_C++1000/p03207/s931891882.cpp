#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> p(n);

  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (i == n - 1)
    {
      ans += p[i] / 2;
      break;
    }
    ans += p[i];
  }
  cout << ans << endl;
}
