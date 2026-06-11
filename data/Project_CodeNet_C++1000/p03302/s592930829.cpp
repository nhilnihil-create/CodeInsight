#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int a, b;
  cin >> a >> b;
  if (a + b == 15) {
    cout << '+' << endl;
  } else if (a * b == 15) {
    cout << '*' << endl;
  } else {
    cout << 'x' << endl;
  }
  return 0;
}