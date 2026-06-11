#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  double t, a;
  cin >> n >> t >> a;
  double sa = 1e6;
  int ans = 0;
  rep(i, n) {
    double h;
    cin >> h;
    double x = t - (h*0.006);
    if(abs(a - x) < sa) {
      sa = abs(a - x);
      ans = i + 1;
    }
  }
  cout << ans << endl;
  return 0;
}