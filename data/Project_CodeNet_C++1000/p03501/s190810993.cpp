#include<bits/stdc++.h>
using namespace std;

signed main()
{
  int n,a,b; cin >> n >> a >> b;
  int ans = min(a*n,b);
  cout << ans << "\n";
}