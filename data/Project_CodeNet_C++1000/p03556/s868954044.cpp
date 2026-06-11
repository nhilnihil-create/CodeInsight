#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n; cin >> n;
  int low = 1, high = n;

  ll res = 0;
  while (low <= high) {
    ll mid = low + (high - low) / 2;

    ll pow = mid * mid;

    if (pow <= n) {
      res = max(res, pow);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << res << "\n";
}
