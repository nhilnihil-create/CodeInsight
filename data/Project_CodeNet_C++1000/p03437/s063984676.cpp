#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int x, y;
  cin >> x >> y;
  if (x % y == 0) {
    puts("-1");
  } else {
    cout << x << '\n';
  }
  return 0;
}
