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

const int MAXN = 1050;

struct box {
  int w, s, v;
};

int n;
vector <box> v;
long long dp[MAXN][10 * MAXN];

bool cmp(box &a, box &b) {
  return a.w + a.s < b.w + b.s;
}

int main() { 

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    box b;
    scanf("%d %d %d", &b.w, &b.s, &b.v);
    v.push_back(b);
  }

  sort(all(v), cmp);
  reverse(all(v));

  dp[0][v[0].s] = v[0].v;
  for (int i = 1; i < n; i++) {
    dp[i][v[i].s] = v[i].v;
    for (int j = 0; j <= 10000; j++) {
      if (dp[i - 1][j] == 0) {
        continue;
      }
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (j >= v[i].w) {
        dp[i][min(j - v[i].w, v[i].s)] = max(dp[i][min(j - v[i].w, v[i].s)], dp[i - 1][j] + v[i].v);
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i <= 10000; i++) {
    ans = max(ans, dp[n - 1][i]);
  }
  cout << ans << endl;

  return 0;
}
