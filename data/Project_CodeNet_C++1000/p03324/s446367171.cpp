#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int d, n;
  cin >> d >> n;
  int c = n == 100 ? 1 : 0;
  ll ans = (n+c) * pow(100, d);
  cout << ans << endl;
  return 0;
}