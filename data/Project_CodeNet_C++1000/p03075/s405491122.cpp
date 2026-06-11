#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;
  int left = max({a, b, c, d, e});
  int right = min({a, b, c, d, e});

  if (left - right <= k)
    cout << "Yay!" << endl;
  else
    cout << ":(" << endl;
}