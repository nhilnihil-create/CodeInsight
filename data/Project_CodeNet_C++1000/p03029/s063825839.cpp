#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int A, P;
  cin >> A >> P;
  P += A * 3;
  int ans = P / 2;
  cout << ans << '\n';
  return 0;
}