#include <iostream>

using namespace std;

int main() {
  int n, d, x, a;
  cin >> n >> d >> x;
  int ans = x;
  for (int i = 0; i < n; i++) {
    cin >> a;
    for (int j = 0; a * j + 1 <= d; j++) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
