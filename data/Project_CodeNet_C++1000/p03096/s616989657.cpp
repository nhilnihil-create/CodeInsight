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

const int MAXN = 2 * 105000;
const int mod = (int) 1e9 + 7;

int n;
int c[MAXN];
map<int, long long> mp;
long long dp[MAXN];

int main() { 

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }

  for (int i = 0; i < n; i++) {
    if (i > 0 && c[i - 1] == c[i]) {
      dp[i] = dp[i - 1];
    } else {
      if (i == 0) {
        dp[i] = 1;
      } else {
        dp[i] = dp[i - 1];
      }
      long long add = dp[i];
      dp[i] = (dp[i] + mp[c[i]]) % mod;
      mp[c[i]] = (mp[c[i]] + add) % mod;
    }
    // cerr << dp[i] << " ";
  }
  // cerr << endl;

  cout << dp[n - 1] << endl;

  return 0;
}
