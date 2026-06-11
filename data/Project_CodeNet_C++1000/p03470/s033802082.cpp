#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int ans = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a.at(i) > a.at(i + 1)) {
      ans++;
    }
  }
  cout << ans << endl;
}