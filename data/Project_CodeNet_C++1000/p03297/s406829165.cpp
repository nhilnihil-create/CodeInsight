#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int tt;

int main() {
  cin >> tt;
  while(tt--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if(min(a, d) < b) {
      cout << "No" << endl;
      continue;
    }
    a %= b;
    if(a > c) {
      cout << "No" << endl;
      continue;
    }
    long long t = __gcd(d, b);
    a %= t;
    if((b - a - 1) / t > (c - a) / t) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
