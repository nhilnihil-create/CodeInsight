#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int h, w;
vector<string> s;
vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

bool func(int i, int j) {
  if (s[i][j] == '.') return true;
  for (int t = 0; t < 4; t++) {
    int x = j + dx[t];
    int y = i + dy[t];
    if (x < 0 || w - 1 < x || y < 0 || h - 1 < y) continue;
    if (s[y][x] == '#') return true;
  }
  return false;
}

int main() {
  cin >> h >> w;
  s.resize(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (func(i, j) == false) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}