#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int x; cin >> x;

  int res = 1;
  for (int b = 2; b < x / 2; ++b) {
    int tmp = b;
    while (tmp <= x) {
      res = max(res, tmp);
      tmp *= b;
    }
  }

  cout << res << "\n";
}
