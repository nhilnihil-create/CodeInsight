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

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs

const int NEED[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int n, m;
int a[15];
int dp[10500];
vector<int> ans;

int main() { 

  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + m);
  reverse(a, a + m);

  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      int use = NEED[a[j]];
      if (i - use >= 0) {
        dp[i] = max(dp[i], 1 + dp[i - use]);
      }
    }
  }

  while (n) {
    // cerr << n << endl;
    for (int j = 0; j < m; j++) {
      int use = NEED[a[j]];
      if (n - use >= 0 && dp[n] == 1 + dp[n - use]) {
        n -= use;
        ans.push_back(a[j]);
        // cerr << a[j] << endl;
        break;
      }
    }
  }

  for (int x : ans) {
    printf("%d", x);
  }
  cout << endl;

  return 0;
}
