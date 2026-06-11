#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int a, b, x;
  cin >> a >> b >> x;
  if (a <= x && x <= a + b) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}