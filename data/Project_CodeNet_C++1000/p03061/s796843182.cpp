#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}
int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> front_gcd(n), back_gcd(n);
  front_gcd[0] = a[0];
  back_gcd[n - 1] = a[n - 1];
  for (int i = 1; i < n; i++) {
    front_gcd[i] = gcd(front_gcd[i - 1], a[i]);
    back_gcd[n - i - 1] = gcd(back_gcd[n - i], a[n - i - 1]);
  }
  int ans = max(front_gcd[n - 2], back_gcd[1]);
  for (int i = 1; i < n - 1; i++) {
    ans = max(ans, gcd(front_gcd[i - 1], back_gcd[i + 1]));
  }
  cout << ans << endl;
  return 0;
}