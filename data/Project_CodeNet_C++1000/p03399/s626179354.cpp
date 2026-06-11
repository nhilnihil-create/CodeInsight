#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int train = min(a, b);
  int bus = min(c, d);
  
  int ans = train + bus;
  cout << ans << endl;
}