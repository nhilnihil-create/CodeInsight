#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
  string S;
  cin >> S;

  int l = (S[0] - '0') * 10 + (S[1] - '0');
  int r = (S[2] - '0') * 10 + (S[3] - '0');

  cerr << l << " " << r << endl;

  bool lm = l <= 12 && l > 0;
  bool rm = r <= 12 && r > 0;

  if (!lm && !rm) puts("NA");
  else if (!lm && rm) puts("YYMM");
  else if (lm && !rm) puts("MMYY");
  else puts("AMBIGUOUS");
}
