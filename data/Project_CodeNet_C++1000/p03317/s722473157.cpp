#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int cnt = 1;
  n -= k;
  while(n > 0) {
    n -= k - 1;
    cnt++;
  }
  cout << cnt << endl;
}