#include <bits/stdc++.h>
using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
int INF = 1e9 + 7;

int main(void) {
  int n, half;
  cin >> n;
  half = (n / 2) + 1;
  vector <double> coins(n);
  ffor(n) cin >> coins[i];
  
  vector <double> dp(half); // dp[i] contains the probability of getting i heads
  dp[0] = 1;
  for(int i = 0; i < coins.size(); i++) {
    double p = coins[i];
    for(int j = dp.size(); j >= 1; j--) {
      /* probablity of getting exactly j heads with the current coin is:
      	p(already gotten heads AND got tails) + p(got j - 1 heads AND got heads)
        */
      dp[j] = dp[j] * (1 - p) + dp[j - 1] * p;
    }
    dp[0] *= (1 - p);
  }
  double total = 0;
  for (auto e: dp) total += e;
  cout << setprecision(12) << 1 - total << '\n';
}