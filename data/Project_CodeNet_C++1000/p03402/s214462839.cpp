#include <bits/stdc++.h>
using namespace std;

int a, b;
char mp[110][110];
int main() {
  cin >> a >> b;
  a--, b--;
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 100; j++) {
      mp[i][j] = '.';
    }
  }
  for (int i = 50; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      mp[i][j] = '#';
    }
  }
  for (int i = 0; i < 50 && b; i += 2) {
    for (int j = 0; j < 100 && b; j += 2) {
      mp[i][j] = '#', b--;
    }
  }
  for (int i = 100 - 1; i >= 50 && a; i -= 2) {
    for (int j = 0; j < 100 && a; j += 2) {
      mp[i][j] = '.', a--;
    }
  }
  cout << 100 << " " << 100 << endl;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      cout << mp[i][j];
    }
    cout << endl;
  }
}
