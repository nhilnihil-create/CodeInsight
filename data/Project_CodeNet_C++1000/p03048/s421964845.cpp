#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int r,g,b,n;
  cin >> r >> g >> b >> n;
  int ans = 0;

  for (int i = 0; i <= n; i += r)
  {
    for (int j = 0; i + j <= n; j += g)
    {
      int now = n - i - j;
      if (now % b == 0) ans++;
    }
  }
  
  
  cout << ans << endl;
  return 0;
}