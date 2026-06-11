#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  double ans = 0;
  rep(i, n) {
    double v;
    string k;
    cin >> v >> k;
    if (k == "JPY") {
      ans += v;
    } else {
      ans += 380000 * v + 0.000001;
    }
  }
  printf("%.6f", ans);
  return 0;
}