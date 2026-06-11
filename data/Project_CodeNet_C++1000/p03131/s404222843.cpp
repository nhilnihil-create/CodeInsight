#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  ll k, a, b;
  cin >> k >> a >> b;

  ll ans;
  if (b <= a + 1) ans = k + 1;

  
  else if (b-a >= 2) {
    if (k <= a) ans = k + 1;  
    else {
      k -= (a-1);//クッキーをa枚にする
      ans = a + (k / 2) * (b-a);
      if (k % 2 == 1) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}