#include <bits/stdc++.h>
using namespace std;
#define int long long
using namespace std;
int a[1000005];
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    a[x] = i;
  }
  int ans = 0;
  int cnt = 1;
  for (int i = 1; i < n; i++)
  {
    if (a[i] < a[i + 1])
    {
      cnt++;
    }
    else
    {
      ans = max(ans, cnt);
      cnt = 1;
    }
  }
  ans = max(ans, cnt);
  cout << n - ans << endl;
  return 0;
}
