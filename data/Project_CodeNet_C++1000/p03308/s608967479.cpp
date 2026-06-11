#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  int max_diff = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int diff = abs(a.at(i) - a.at(j));
      max_diff = max(max_diff, diff);
    }
  }

  cout << max_diff << endl;
  return 0;
}