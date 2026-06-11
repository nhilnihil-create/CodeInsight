#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;

  if (max({a, b, c, d, e}) - min({a, b, c, d, e}) > k)
    cout << ":(" << endl;
  else
    cout << "Yay!" << endl;
  return 0;
}