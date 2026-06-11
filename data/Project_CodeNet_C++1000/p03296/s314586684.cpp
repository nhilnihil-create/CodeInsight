#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int ans = 0;
  int cnt = 1;
  for (int i = 1; i < N; i++) {
    if (a[i] == a[i - 1])
      cnt++;
    else {
      ans += cnt / 2;
      cnt = 1;
    }
  }
  cout << ans + cnt / 2 << endl;
  return 0;
}