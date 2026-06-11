#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  int l = 0, r = 0;
  for (int i = 0; i < m; i++) {
    if (a[i] < x)
      l++;
    else
      r++;
  }
  cout << min(l, r) << endl;
  return 0;
}