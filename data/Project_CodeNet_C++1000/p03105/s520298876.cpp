#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAX32 = 2147483647;
const double PI = 3.14159265358979323846;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (b > a * c) {
    cout << c << endl;
  } else {
    cout << b / a << endl;
  }
}
