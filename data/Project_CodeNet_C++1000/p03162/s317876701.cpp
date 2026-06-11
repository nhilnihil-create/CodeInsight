#include <bits/stdc++.h>
using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)

struct day{
  int a, b, c;
  day(int _a, int _b, int _c) {
    a = _a; b = _b; c = _c;
  }
};

int main(void) {
  int n, a, b, c;
  cin >> n;
  vector <day> v(n, day(0, 0, 0));
  ffor(n) {
    cin >> a >> b >> c;
    v[i] = day(a, b, c);
  }
  vector <day> dp(n, day(0, 0, 0)); // let dp[i] be the total happiness up to that day
  dp[0] = v[0];
  for(int i = 1; i < n; i++) {
    dp[i] = day(max(dp[i - 1].b, dp[i - 1].c) + v[i].a, 
                max(dp[i - 1].a, dp[i - 1].c) + v[i].b, 
                max(dp[i - 1].a, dp[i - 1].b) + v[i].c);
  }
  a = dp.back().a, b = dp.back().b, c = dp.back().c;
  cout << max({a, b, c}) << '\n';
}