#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    ll a, b;
    cin >> a >> b;
    if (a>b) swap(a, b);
    ll k = floor(sqrt((long double)a*b-1));
    if (a==b || a+1==b) {
      cout << 2*(a-1) << "\n";
    } else if (k*(k+1)>=a*b) {
      cout << 2*(k-1) << "\n";
    } else {
      cout << 2*k-1 << "\n";
    }
  }
  return 0;
}
