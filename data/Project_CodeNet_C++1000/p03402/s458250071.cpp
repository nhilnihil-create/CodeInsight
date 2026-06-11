#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  vector < string > ans(100, string(100, '.'));
  for (int i = 0; i < 50; ++i)
    ans[i] = string(100, '#');
  int cnt = a - 1;
  for (int i = 1; i < 49 && cnt; i += 2) {
    for (int j = 1; j < 99 && cnt; j += 2) {
      ans[i][j] = '.';
      --cnt;
    }
  }
  cnt = b - 1;
  for (int i = 51; i < 99 && cnt; i += 2) {
    for (int j = 1; j < 99 && cnt; j += 2) {
      ans[i][j] = '#';
      --cnt;
    }
  }
  cout << 100 << ' ' << 100 << '\n';
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j)
      cout << ans[i][j];
    cout << '\n';
  }
}
