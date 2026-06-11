#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b;
  cin >> a >> b;
  int ie = b - a;
  int he = 0;
  for (int i = 1; i <= ie; i++) he += i;
  int ans = he - b;
  cout << ans << endl;
  return 0;
}