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
int dp; // i個目までの文字列を分割した時の分割数の最小値
vector<int> dp2(1<<26, 1e9); // ハッシュ値ごとの分割数の最小値
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s; cin >> s;
  int N = s.length();
  ll x = 0; // i個目までのハッシュ値
  dp = 0; 
  dp2[0] = 0;
  FOR(i,0,N) {
    x ^= 1LL << (s[i] - 'a');
    int ma = min((int)1e9, dp2[x]);
    FOR(j,0,26) {
      ll y = x ^ (1LL << j);
      ma = min(ma, dp2[y]);
    }
    dp2[x] = min(dp2[x], ma + 1);
    dp = ma + 1;
  }
  cout << dp << endl;
  return 0;
}