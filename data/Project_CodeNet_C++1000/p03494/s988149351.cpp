#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n; cin >> n;

  int res = ~(1 << 31);

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    int lsb_distance = floor(log2(x & -x));
    res = min(res, lsb_distance);
  }

  cout << res << "\n";
}
