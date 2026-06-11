#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
  int d, g;
  cin >> d >> g;
  g /= 100;
  vector<int> p(d), c(d), s(d), u(d);
  for (int i = 0; i < d; i++) {
    cin >> p[i] >> c[i];
    c[i] /= 100;
    s[i] = (i + 1) * p[i] + c[i];
    u[i] = s[i] - (i + 1) - c[i];
  }
  int ans = 10000;
  for (int x = 0; x < (1 << d); x++) {
    int uncomp = -1;
    int sum = 0;
    int temp = 0;
    for (int i = 0; i < d; i++) {
      if (x & (1 << i))  {
        sum += s[i];
        temp += p[i];
      } else {
        uncomp = i;
      }
    }
    if (sum >= g) {
      ans = min(ans, temp);
    } else if (sum + u[uncomp] >= g) {
      ans = min(ans, temp + (g - sum - 1) / (uncomp + 1) + 1);
    }
  }
  cout << ans << endl;
  return 0;
}