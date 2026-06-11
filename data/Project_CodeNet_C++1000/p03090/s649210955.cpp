#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
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
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 998244353;
long long INF = 1000000000000000;

typedef long long ll;

int main(void) {
  int n; cin >> n;
  cout << n * (n - 1) / 2 - n / 2 << endl;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (i + j + 2 == n + 1 - n % 2) continue;
      cout << i + 1 << " " << j + 1 << endl;
    }
  }
  return 0;
}
