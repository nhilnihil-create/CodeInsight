#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int ans = 0;
  vector<int> v(3);
  for (int i = 0; i < 3; i++)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  int a, b;
  a = v[2] - v[0];
  b = v[2] - v[1];

  if (a % 2 == 1 && b % 2 == 1)
  {
    ans++;
    ans += ((a - 1) / 2) + ((b - 1) / 2);
  }
  else if (a % 2 == 0 && b % 2 == 1)
  {
    ans++;
    ans += (a / 2) + ((b + 1) / 2);
  }
  else if (a % 2 == 1 && b % 2 == 0)
  {
    ans++;
    ans += ((a + 1) / 2) + (b / 2);
  }
  else
  {
    ans += (a / 2) + (b / 2);
  }
  cout << ans << endl;
}
