#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <iomanip>
#include <bitset>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>

using namespace std;

const int N = 200005;

int n;
char a[N];
int x;
map <int, int> m;

int main() {
  scanf(" %s", a);
  n = strlen(a);
  m[0] = 0;
  for (int i = 0; i < n; i++) {
    x ^= (1 << (a[i] - 'a'));
    int here = i + 1;
    if (m.count(x)) {
      here = min(here, m[x] + 1);
    }
    for (int j = 0; j < 26; j++) {
      if (m.count(x ^ (1 << j))) {
        here = min(here, m[x ^ (1 << j)] + 1);
      }
    }
    if (m.count(x)) {
      m[x] = min(m[x], here);
    } else {
      m[x] = here;
    }
    if (i == n - 1) {
      printf("%d\n", here);
    }
  }
  return 0;
}
