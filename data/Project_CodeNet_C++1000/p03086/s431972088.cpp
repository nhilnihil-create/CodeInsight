#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  string S;
  cin >> S;
  string pat = "ACGT";
  int ans = 0, tot = 0;
  rep(i, 0, S.size()) {
    if (pat.find(S[i]) != pat.npos)
      tot++;
    else
      tot = 0;
    ans = max(ans, tot);
  }
  cout << ans << endl;

  return 0;
}
