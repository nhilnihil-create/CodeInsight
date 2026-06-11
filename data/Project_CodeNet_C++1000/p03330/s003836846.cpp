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

const int MAXN = 500;

int n, cn;
int c[MAXN][MAXN];
int d[MAXN][MAXN];
int cost[3][100];
int ans = 1e9;

int main() { 

  scanf("%d %d", &n, &cn);
  for (int i = 0; i < cn; i++) {
    for (int j = 0; j < cn; j++) {
      scanf("%d", &d[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &c[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cur = (i + j) % 3;
      for (int k = 0; k < cn; k++) {
        cost[cur][k] += d[c[i][j] - 1][k];
      }
    }
  }

  for (int i = 0; i < cn; i++) {
    for (int j = 0; j < cn; j++) {
      for (int k = 0; k < cn; k++) {
        if (i == j || i == k || j == k) {
          continue;
        }
        ans = min(ans, cost[0][i] + cost[1][j] + cost[2][k]);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
