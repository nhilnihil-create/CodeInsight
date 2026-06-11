#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

const ld pi = 3.141592653589793;

#ifdef EBUG
#define debug(x) cout << "\033[31m" << #x << ": " << x << "\033[0m\n";
#else
#define debug(x)
#endif

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll n, m;
string s[105], t[105];
map<string, int> memo;

int main() {
  cin >> n;
  rep(i, n) {
    cin >> s[i];
    memo[s[i]]++;
  }
  cin >> m;
  rep(i, m) {
    cin >> t[i];
    memo[t[i]]--;
  }

  int ans = 0;
  for (auto i = memo.begin(); i != memo.end(); i++) {
    ans = max(ans, (*i).second);
  }
  cout << ans << endl;
}