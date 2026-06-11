#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
#include<numeric>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  string s;
  cin >> s;

  int l = s.size();

  bool a = false, b = false;
  ll aCount = 0;
  ll result = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] == 'A') {
      if (a && !b) aCount++;
      else aCount = 1;
      a = true;
      b = false;
    } else if (s[i] == 'B' && a && !b) {
      b = true;
    } else if (s[i] == 'C' && a && b) {
      result += aCount;
      a = true;
      b = false;
    } else {
      aCount = 0;
      a = false;
      b = false;
    }
  }
  cout << result << endl;
}
