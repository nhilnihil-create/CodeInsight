#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  double ans = 0;
  rep(i,0,n) {
    double x; string u;
    cin >> x >> u;
    if (u == "JPY") ans += x;
    else {
      ans += x * 380000;
    }
  }
  printf("%.6lf", ans);
  return 0;
}
