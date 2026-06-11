#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, x;
  cin >> n >> x;

  int mn = ~(1 << 31);
  for (int i = 0; i < n; ++i) {
    int y; cin >> y;
    x -= y;
    mn = min(mn, y);
  }

  int res = n;
  cout << res + (x / mn) << "\n";
}
