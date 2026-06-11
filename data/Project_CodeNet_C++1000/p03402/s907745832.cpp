#include <bits/stdc++.h>
using namespace std;

long long a, b, h = 100, w = 100;
string ans[100];

void solve();

int main() {
  cin >> a >> b;
  solve();
  cout << h << " " << w << endl;
  for(int i = 0; i < h; ++i) cout << ans[i] << endl;
  return 0;
}

void solve() {
  int cnt = 1;
  for(int i = 0; i < 50; ++i)
    for(int j = 0; j < 100; ++j) ans[i] += "#";
  for(int i = 0; i < 50; ++i)
    for(int j = 0; j < 100; ++j) ans[i + 50] += ".";
  for(int i = 0; i < 50; i += 2) {
    for(int j = 0; j < 100; j += 2) {
      if(cnt == a) break;
      ans[i][j] = '.';
      ++cnt;
    }
    if(cnt == a) break;
  }
  cnt = 1;
  for(int i = 51; i < 100; i += 2) {
    for(int j = 0; j < 100; j += 2) {
      if(cnt == b) break;
      ans[i][j] = '#';
      ++cnt;
    }
    if(cnt == b) break;
  }
}