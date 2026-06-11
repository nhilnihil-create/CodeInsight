#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;

int main() {
  int a, b, c, x, y;
  cin >>a >> b >> c >> x >> y;
  int sum = 0;
  int num1 = min(x, y);
  int price1 = min((a+b), c*2);
  sum += price1 * num1;

  int price2 = x < y ? b : a;
  price2 = price2 < c*2 ? price2 : c*2;
  int num2 = max(x, y) - min(x, y);
  sum += price2*num2;

  cout << sum << endl;
  return 0;
}
