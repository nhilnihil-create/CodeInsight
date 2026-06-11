// g++ A.cpp -Wall -Wextra -Woverflow -Wshadow -O2
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <cmath>
#include <iomanip>
#include <set>
#include <bitset>

using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;

const int MAXN = 1 << 17;
int n;
int a[MAXN];
vector<int> b;
LL BIT[4 * MAXN];

LL read(int idx) {
  LL sum = 0;
  while (idx > 0) {
    sum += BIT[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

void update(int idx, LL val) {
  while (idx < 4 * MAXN) {
    BIT[idx] += val;
    idx += (idx & -idx);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b.push_back(a[i]);
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  int L = 0, R = b.size() - 1;
  while (L < R) {
    int mid = (L + R + 1) / 2;
    int x = b[mid];
    int pref = 0;
    LL cnt = 0;
    memset(BIT, 0LL, sizeof(BIT));
    update(MAXN, 1LL);
    for (int i = 0; i < n; i++) {
      int val = (a[i] >= x ? 1 : -1);
      pref += val;
      LL tot = read(MAXN + pref); 
      cnt += tot;
      update(MAXN + pref, 1LL);
    }
    if (cnt >= (LL)n * (LL)(n + 1LL) / 4LL) {
      L = mid;
    } else {
      R = mid - 1;
    }
  }
  cout << b[L] << endl;
} 