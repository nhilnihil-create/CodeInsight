#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  int ans = 0;
  for (int i = 0; i < 100; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (h[j] == 0)
        continue;
      h[j]--;
      if (j == n - 1 || h[j + 1] == 0)
      {
        ans++;
      }
    }
  }
  cout << ans << endl;
}