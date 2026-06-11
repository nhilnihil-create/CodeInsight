#include <bits/stdc++.h>
using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
int INF = 1e9 + 7;
long long INF2 = 1e16;

int main(void) {
  int n;
  char c;
  cin >> n;
  vector <vector <bool>> v(n, vector <bool>(n));
  ffor(n) {
    fffor(n) {
      cin >> c;
      if (c == '0') v[i][j] = 0;
      else v[i][j] = 1;
    }
  }
  
  int max_mask = (1 << n) - 1;
  vector <long long> dp(max_mask + 1);
  dp[0] = 1;
  
  for(int mask = 0; mask < max_mask; mask++) {
    int bit_num = __builtin_popcount(mask);
    for(int i = 0; (1 << i) <= max_mask; i++) {
      if (((1 << i) & mask) == 0 && v[i][bit_num] == 1) {
        int new_mask = mask | (1 << i);
        dp[new_mask] += dp[mask];
        dp[new_mask] %= INF;
      }
    }
  }
  cout << dp.back() << '\n';
}