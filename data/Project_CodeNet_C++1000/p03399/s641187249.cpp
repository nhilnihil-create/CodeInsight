#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = min(a, b) + min(c, d);
  cout << ans;
}
