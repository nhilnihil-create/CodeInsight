#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int dp;
vector<int> dp2(1LL<<26, 1e9);
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s; cin >> s;
  int x = 0;
  dp = dp2[0] = 0;
  FOR(i,0,s.length()) {
    x ^= 1LL << (s[i] - 'a');
    int m = dp2[x];
    FOR(j,0,26) {
      m = min(m, dp2[x^(1LL<<j)]);
    }
    dp2[x] = min(dp2[x], m + 1);
    dp = m + 1;
  }
  cout << dp << endl;
  return 0;
}