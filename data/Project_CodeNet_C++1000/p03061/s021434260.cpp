#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  vector<int> a(n), l(n+1), r(n+1);
  rep(i,n) cin >> a[i];
  
  a.push_back(0);
  exclusive_scan(a.begin(), a.end(), l.begin(), 0,
                [](int x, int y) {return gcd(x, y); });
  exclusive_scan(a.rbegin(), a.rend(), r.rbegin(), 0,
                [](int x, int y) {return gcd(x, y); });
  
  int ans = 0;
  rep(i,n+1)
    ans = max(ans, gcd(l[i], r[i]));
  
  cout << ans << endl;
  return 0;
}