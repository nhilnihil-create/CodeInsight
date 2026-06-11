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

const int MAXN = 3050;
const int mod = (int) 1e9 + 7;

int n;
string s;
long long dp[MAXN][MAXN];
long long sum[MAXN][MAXN];

int main() { 

  scanf("%d\n", &n);
  getline(cin, s);

  dp[1][1] = 1; sum[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    bool less = (s[i - 2] == '<');
    for (int j = 1; j <= i; j++) {
      if (less) {
        dp[i][j] = sum[i - 1][j - 1];
      } else {
        dp[i][j] = sum[i - 1][i - 1] - sum[i - 1][j - 1];
        if (dp[i][j] < 0) {
          dp[i][j] += mod;
        }
      }
    }
    sum[i][1] = dp[i][1];
    for (int j = 2; j <= i; j++) {
      sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
    }
  }

  cout << sum[n][n] << endl;

  return 0;
}
