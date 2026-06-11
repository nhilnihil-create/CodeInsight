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

const int MAXN = 305;

int n;
char c[2 * MAXN][2 * MAXN];
int dp[2 * MAXN][2 * MAXN];
int dp2[2 * MAXN][2 * MAXN];

int main() { 

  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%c", &c[i][j]);
    }
    scanf("\n");
  }
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < 2 * n; j++) {
      if (c[i][j] != 0) {
        continue;
      }
      c[i][j] = c[i % n][j % n];
    }
  }

  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < 2 * n; j++) {
      dp[i][j] = 1;
      int li = i, lj = j;
      int ri = i, rj = j;
      while (true) {
        li++; lj--;
        ri--; rj++;
        if (li >= 2 * n || lj < 0 || ri < 0 || rj >= 2 * n) {
          break;
        }
        if (c[li][lj] != c[ri][rj]) {
          break;
        }
        dp[i][j]++;
      }
    }
  }

  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < 2 * n; j++) {
      dp2[i][j] = 0;
      int li = i, lj = j;
      int ri = i - 1, rj = j + 1;
      while (true) {
        if (li >= 2 * n || lj < 0 || ri < 0 || rj >= 2 * n) {
          break;
        }
        if (c[li][lj] != c[ri][rj]) {
          break;
        }
        dp2[i][j]++;
        li++; lj--;
        ri--; rj++;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int si = i, sj = j;
      int len = 1;
      int dl = 1;
      bool good = true;

      for (int k = 0; k < 2 * n - 1; k++) {
        if (k % 2 == 0) {
          if (2 * dp[si][sj] - 1 < len) {
            good = false;
            break;
          }
        } else {
          if (2 * dp2[si][sj] < len) {
            good = false;
            break;
          }
        }
        if (k % 2 == 0) {
          si++;
        } else {
          sj++;
        }
        if (len == n) {
          dl = -1;
        }
        len += dl;
      }

      if (good) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
