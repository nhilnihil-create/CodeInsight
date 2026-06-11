#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n, m;
  cin >> n >> m;

  int l = 0, r = 1e6;

  rep(i, m)
  {
    int left, right;
    cin >> left >> right;
    r = min(r, right);
    l = max(l, left);
  }

  if (l <= r)
  {
    cout << r - l + 1;
  }
  else
  {
    cout << 0;
  }

}
