#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t X, Y; cin >> X >> Y;
  int ans = 0;
  while (Y >= X) {
    Y /= 2;
    ans++;
  }
  cout << ans << endl;  
}