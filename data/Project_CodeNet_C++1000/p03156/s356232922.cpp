#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> p(n);
  for (auto& e : p)
    cin >> e;

  int c1 = 0, c2 = 0, c3 = 0;

  for (auto e : p) {
    if (e <= a)
      ++c1;
    else if (e <= b)
      ++c2;
    else
      ++c3;
  }

  int ans = min({c1, c2, c3});
  cout << ans << endl;
}