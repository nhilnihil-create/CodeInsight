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

const int MAXN = 16;

int n;
int a[MAXN][MAXN];
long long cost[(1 << MAXN) + 1023];
long long dp[(1 << MAXN) + 1023];

int main() { 

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        cost[i] = cost[i ^ (1 << j)];
        for (int k = j + 1; k < n; k++) {
          if (i & (1 << k)) {
            cost[i] += a[j][k];
          }
        }
        break;
      }
    }
  }

  for (int i = 0; i < (1 << n); i++) {
    for (int submask = i; submask >= 0; submask = (submask - 1) & i) {
      dp[i] = max(dp[i], dp[submask] + cost[i - submask]);
      if (submask == 0) {
        break;
      }
    }
  }

  cout << dp[(1 << n) - 1] << endl;

  return 0;
}
