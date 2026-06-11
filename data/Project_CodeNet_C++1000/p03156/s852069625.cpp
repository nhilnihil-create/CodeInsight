#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  int x, y, z;
  x = y = z = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] <= a)
      x++;
    else if (p[i] <= b)
      y++;
    else
      z++;
  }
  cout << min({x, y, z}) << endl;
  return 0;
}