#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a,b;
  cin >> a>>b;
  int ans;
  if(a <=5) ans = 0;
  else if(a >=6 && a <= 12) ans = b/2;
  else ans = b;
  cout << ans << endl;
}