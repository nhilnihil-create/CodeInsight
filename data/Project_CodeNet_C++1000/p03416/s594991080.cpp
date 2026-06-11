#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int a, b, n, t;
  int k1, k2, k3, k4, k5;
  cin >> a >> b;
  n = b - a + 1;
  int ans = 0;
  int r = a;
  rep(i, n) {
    k5 = r % 10;
    t = r / 10;
    k4 = t % 10;
    t /= 10;
    k3 = t % 10;
    t /= 10;
    k2 = t % 10;
    t /= 10;
    k1 = t % 10;
    if (k1 == k5 && k2 == k4) ans++;
    r++;
  }
  cout << ans << endl;
}
