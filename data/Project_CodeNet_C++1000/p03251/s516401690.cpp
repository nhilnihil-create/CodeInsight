#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m, x, y;
  cin >> n >> m >> x >> y; 
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b(m);
  for (int i = 0; i < m; i++) 
    cin >> b[i];
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  for (int z = x + 1; z <= y; z++) {
    if (z > a.back() && b[0] >= z) {
      cout << "No War\n";
      return 0;
    }
  }
  cout << "War\n";
  return 0;
}