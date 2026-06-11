#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int a, b, c, ans;

int main() {
  ans = 0;
  cin >> a >> b >> c;
  if (a%2 + b%2 + c%2 == 1) {
    if (a % 2 == 0) a++;
    if (b % 2 == 0) b++;
    if (c % 2 == 0) c++;
    ans = 1;
  } else if (a%2 + b%2 + c%2 == 2) {
    if (a % 2 == 1) a++;
    if (b % 2 == 1) b++;
    if (c % 2 == 1) c++;
    ans = 1;
  }
  ans += (3*max({a, b, c}) - (a+b+c)) / 2;
  cout << ans << endl;
  return 0;
}
