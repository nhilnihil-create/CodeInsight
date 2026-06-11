#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,x;cin >> n >> x;
  vector<int> a(n);
  long long  check = 0;
  for (auto &&i: a)
  {
    cin >> i;
    check += i;
  }
  if (check < x)
  {
    cout <<  n - 1 << endl;
    return 0;
  }
  sort(a.begin(), a.end());
  long long sum = 0;
  int ans = 0;
  for (ans; ans < n; ans++)
  {
    sum += a[ans];
    if (sum > x)
    {
      break;
    }
  }
  cout << ans << endl;
}
