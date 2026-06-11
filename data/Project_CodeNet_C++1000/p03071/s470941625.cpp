#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a,b;
  cin >> a >> b;
  int ans = max(a,b);
  if(a == ans) a--;
  else b--;
  ans += max(a,b);
  cout << ans << endl;
  return 0;
}
