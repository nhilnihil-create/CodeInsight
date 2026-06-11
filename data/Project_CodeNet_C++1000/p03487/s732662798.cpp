#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> a;
  for (int i = 0; i < n; i++) {
    int ii;
    cin >> ii;
    a[ii] = a[ii] + 1;
  }
  int res = 0;
  for (auto itr = a.begin(); itr != a.end(); ++itr) {
    res += (itr->second) - (itr->first) >= 0 ? (itr->second) - (itr->first)
                                             : itr->second;
  }
  cout << res << endl;
  return 0;
}
