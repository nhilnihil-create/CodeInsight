#include <iostream>
using namespace std;

int f(int n) {
  int res = 0;
  for(int i = 1; i <= n; i++) {
    if(n % i == 0) res++;
  }
  return res;
}

int main() {
  int n; cin >> n;
  if(n < 105) cout << 0 << endl;
  else {
    int ans = 0;
    for(int i = 105; i <= n; i+=2) {
      if(f(i) == 8) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
