#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t K, A, B; cin >> K >> A >> B;
  
  if (K < A + 1 || B - A < 2) { cout << K + 1 << endl; return 0; }
  
  int64_t ans = B + ((K - A + 1) / 2 - 1) * (B - A);
  
  if ((K - A + 1) % 2 == 0) cout << ans << endl;
  
  else cout << ans + 1 << endl;
  
}