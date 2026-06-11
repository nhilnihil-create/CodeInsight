#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

int main(void)
{
  int n, x, y;
  cin >> n >> x >> y;
  cout << min(x, y) << " " << max(0, x + y - n) << endl;
}
