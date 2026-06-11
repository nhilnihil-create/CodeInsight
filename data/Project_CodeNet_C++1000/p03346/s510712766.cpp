#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

const int MAXN = 205000;
const int INF = 1e9;

class SegmentTree {
private: 
  long long tree[4 * MAXN];
  int num;
public:
  void init(int n) {
    num = 1;
    while (num < n) {
      num *= 2;
    }
    for (int i = 1; i < 2 * num; i++) {
      tree[i] = INF;
    }
  }

  long long getMin(int l, int r) {
    l = num + l; r = num + r;
    long long res = INF;
    
    while (l <= r) {
      if (l & 1) {
        res = min(res, tree[l]);
        l++;
      }
      if (r % 2 == 0) {
        res = min(res, tree[r]);
        r--;
      }
      l /= 2; r /= 2;
    }

    return res;
  }

  void update(int pos, long long val) {
    pos = num + pos;
    tree[pos] = val;
    pos /= 2;
    while (pos >= 1) {
      tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
      pos /= 2;
    }
  }
};

int n;
int p[MAXN];
int pos[MAXN];
int ans = -1;
SegmentTree t;

int main() { 

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    pos[p[i]] = i;
  }

  t.init(n);

  int mnInv = -1;
  for (int i = n; i >= 0; i--) {
    int cur = i;
    if (mnInv != -1) {
      cur += (n - mnInv + 1);
    }
    if (ans == -1 || cur < ans) {
      ans = cur;
    }

    int curMn = t.getMin(0, pos[i] - 1);
    if (curMn != INF && (mnInv == -1 || curMn < mnInv)) {
      mnInv = curMn;
    }
    t.update(pos[i], i);
  }

  cout << ans << endl;

  return 0;
}
