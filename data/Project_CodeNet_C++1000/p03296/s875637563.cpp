#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int last = 10000;
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      a[i] = last--;
      ++cnt;
    }
  }
  cout << cnt << endl;
}
