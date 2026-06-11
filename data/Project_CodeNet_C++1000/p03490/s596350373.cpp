#include <bits/stdc++.h>

#define mp make_pair

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef pair<int,int> pii;
typedef pair<i64,int> pli;
typedef pair<int,i64> pil;
typedef pair<i64,i64> pll;
typedef vector<int> vi;
typedef vector<i64> vl;

const int MAX_N = 8000;
string s;
int x,y;
bool dp[MAX_N][2*MAX_N+5] = {};
vi vd, hd;

int main()
{
  cin >> s >> x >> y;
  s.push_back('T');
  int r = 0;
  int i = 0;
  while (s[i++] == 'F') r++;
  bool v = true;
  int c = 0;
  for (; i < (int)s.length(); i++) {
    if (s[i] == 'T') {
      if (v) vd.push_back(c);
      else hd.push_back(c);
      c = 0;
      v = !v;
    } else {
      c++;
    }
  }

  /*
  cout << "[hd]" << hd.size() << endl;
  for (int i : hd) cout << i << endl;
  cout << "[vd]" << vd.size() << endl;
  for (int i : vd) cout << i << endl;
  */

  dp[0&1][MAX_N+r] = true;
  for (int i = 0; i < (int)hd.size(); i++) {
    fill_n(dp[1-(i&1)], 2*MAX_N+5, false);
    for (int j = 0; j <= 2*MAX_N; j++) {
      if (dp[i&1][j]) {
        if (j-hd[i] >= 0) dp[1-(i&1)][j-hd[i]] = true;
        if (j+hd[i] <= 2*MAX_N) dp[1-(i&1)][j+hd[i]] = true;
      }
    }
  }

  if (!dp[hd.size()&1][MAX_N+x]) {
    cout << "No" << endl;
    return 0;
  }

  fill_n(dp[0], 2*MAX_N+5, false);
  dp[0][MAX_N] = true;
  for (int i = 0; i < (int)vd.size(); i++) {
    fill_n(dp[1-(i&1)], 2*MAX_N+5, false);
    for (int j = 0; j <= 2*MAX_N; j++) {
      if (dp[i&1][j]) {
        if (j-vd[i] >= 0) dp[1-(i&1)][j-vd[i]] = true;
        if (j+vd[i] <= 2*MAX_N) dp[1-(i&1)][j+vd[i]] = true;
      }
    }
  }

  if (!dp[vd.size()&1][MAX_N+y]) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}
