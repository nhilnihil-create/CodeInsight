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

const int INF = 1001001001;

int f(string s) {
  set<char> ss;
  for (auto c : s) ss.insert(c);
  return ss.size();
}

int main() {
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  rep(i, 0, N) {
    rep(j, 1, N) {
      set<string> sx, sy;
      string x = S.substr(0, j);
      string y = S.substr(j, S.size());
      int cnt = 0;
      rep(k, 0, 26) {
        char c = 'a' + k;
        if (x.find_first_of(c) == string::npos ||
            y.find_first_of(c) == string::npos)
          continue;
        cnt++;
      }
      ans = max(ans, cnt);
    }
  }

  cout << ans << endl;

  return 0;
}
