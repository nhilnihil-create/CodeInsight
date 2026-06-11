#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int N;
  cin >> N;
  double ans;
  REP(i, N) {
    double x;
    string v;
    cin >> x >> v;
    if (v == "JPY") {
      ans += x;
    } else {
      ans += x * 380000;
    }
  }
  printf("%.8f\n", ans);
  return 0;
}