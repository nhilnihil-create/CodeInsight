#include <bits/stdc++.h>

using namespace std;

bitset<4000002>s;
int n, x, sum;

int main()
{
  cin >> n;
  s[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    s = s | (s << x);
    sum += x;
  }
  int t  = (sum + 1) / 2;
  for (int i = t; i <= sum; i++)
    if (s[i]) {
      cout << i;
      return 0;
    }
  return 0;
}
