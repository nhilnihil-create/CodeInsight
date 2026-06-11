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

bool isACGT(char c) { return c == 'A' || c == 'C' || c == 'G' || c == 'T'; }

int main() {
  string S;
  cin >> S;
  int ans = 0;
  int tot = 0;
  rep(i, 0, S.size()) {
    if (isACGT(S[i]))
      tot++;
    else
      tot = 0;
    ans = max(ans, tot);
  }
  cout << ans << endl;

  return 0;
}
