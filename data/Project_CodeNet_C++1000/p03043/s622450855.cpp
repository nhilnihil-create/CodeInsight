#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n, k;
  cin >> n >> k;
  double ans = 0;
  for (int i = n; i >= 1; i--)
  {
    /*if (i >= k) {
      ans += 1/n;
      continue;
    }*/
    double p = 1;
    int x = i;
    while (x < k) {
      x *= 2;
      p *= 0.5;
    }
    
    ans += p / n;
  }
  cout << setprecision(10);
  cout << ans << endl;
  return 0;
}