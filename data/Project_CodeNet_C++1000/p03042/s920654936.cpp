#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define MOD 1000000007

bool numjdg(char a, char b) {
  if (a == '0') {
    if (b != '0') return true;
  } else if (a == '1') {
    if (b == '0' || b == '1' || b == '2') return true;
  }
  return false;
}

int main()
{
  string s, ans;
  cin >> s;
  bool before = numjdg(s[0], s[1]);
  bool after = numjdg(s[2], s[3]);
  if (before && after) ans = "AMBIGUOUS";
  else if (before && !after) ans = "MMYY";
  else if (!before && after) ans = "YYMM";
  else ans = "NA";

  cout << ans << endl;

  return 0;
}
