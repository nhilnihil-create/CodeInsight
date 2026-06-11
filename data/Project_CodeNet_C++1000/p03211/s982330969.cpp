#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t s;
  cin >> s;
  
  int64_t pro = 100, ans = 1000;
  int64_t x;
  bool bo = true;
  
  while (bo) {
    pro *= 10;
    x = abs((((s % pro) - (s % (pro / 1000))) / (pro / 1000)) - 753);
    ans = min(ans, x);
    if (s < pro) {
      bo = false;
    }
  }
  cout << ans << endl;
}
