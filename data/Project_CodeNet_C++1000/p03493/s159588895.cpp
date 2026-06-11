#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  int s1 = a / 100;
  int b = a - s1 * 100;
  int s2 = b / 10;
  int c = b - s2 * 10;
  int s3 = c;
  int ans = s1 + s2 + s3;
  cout << ans << endl;
}