#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

int main(void) {

  int b, w;
  cin >> w >> b;

  char s[110][30] = {};
  rep(i, 100) rep(j, 21) s[i][j] = '#';
  int wc = w - 1;
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < 100; j += 2) {
      if (wc > 0 && s[j][i - 1] == '#') {
	wc--;
	s[j][i] = '.';
      }
    }
  }

  char t[110][30] = {};
  rep(i, 100) rep(j, 21) t[i][j] = '.';
  int bc = b - 1;
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < 100; j += 2) {
      if (bc > 0 && t[j][i - 1] == '.') {
	bc--;
	t[j][i] = '#';
      }
    }
  }

  cout << 100 << " " << 42 << endl;
  rep(i, 100) cout << s[i] << t[i] << endl;

  return 0;
}
  
