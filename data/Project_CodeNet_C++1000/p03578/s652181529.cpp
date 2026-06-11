#include <bits/stdc++.h>
using namespace std;

long long n, m;
map<int, int> mp;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++mp[a];
  }
  cin >> m;
  bool ch = 1;
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    if (--mp[a] < 0) ch = 0;
  }
  if (ch)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
