#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  a--;
  b--;

  char map[100][100] = {};
  REP(i, 100) {
    REP(j, 100) {
      if (i < 50) {
        map[i][j] = '.';
      } else {
        map[i][j] = '#';
      }
    }
  }

  int c = 0;
  while (b > 0) {
    int i = c / 100;
    int j = c % 100;
    if (i % 2 == 0) {
      c += 2;
      continue;
    }
    map[i][j] = '#';
    b--;
    c += 2;
  }

  c = 5000;
  while (a > 0) {
    int i = c / 100;
    int j = c % 100;
    if (i % 2 == 0) {
      c += 2;
      continue;
    }
    map[i][j] = '.';
    a--;
    c += 2;
  }

  cout << 100 << " " << 100 << endl;
  REP(i, 100) {
    REP(j, 100) { cout << map[i][j]; }
    cout << endl;
  }
}
