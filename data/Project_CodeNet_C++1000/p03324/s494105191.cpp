#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int d, n;
  cin >> d >> n;
  int t = 1;
  for (int i = 1; i <= d; i++) t *= 100;
  if (n == 100) t *= (n + 1);
  else t *= n;
  cout << t << '\n';
}
