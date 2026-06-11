#include <iostream>
using namespace std;

long long a, b, c, d;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

bool solve() {
  if (a < b) return false;
  if (d < b) return false;
  if (c >= b-1) return true;

  long long g = GCD(b, d);

  // g で割って a%g あまる数で、c より大きく b 未満な整数があるかどうか
  // g で割って a%g あまる数で、b 未満の最大の数
  long long Max = (b - a%g + g-1)/g*g + a%g - g; // b が g の倍数であることを考慮して、Max = b + a%g - g でも OK
  if (Max > c) return false;
  else return true;
}

int main() {
  int T; cin >> T;
  for (int CASE = 0; CASE < T; ++CASE) {
    cin >> a >> b >> c >> d;
    if (solve()) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}