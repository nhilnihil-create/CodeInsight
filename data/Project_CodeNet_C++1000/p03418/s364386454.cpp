// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

int main() {
  ll n, k; cin >> n >> k;
  if (k == 0) {
    cout << n*n << endl;
    return 0;
  }
  
  ll ans = 0;
  loop(b,k+1,n+1) {
    ans += max(b-k, 0LL) * (n/b);
    int r = n%b;
    ans += max(r-k+1, 0LL);
  }
  cout << ans << endl;
  return 0;
}
