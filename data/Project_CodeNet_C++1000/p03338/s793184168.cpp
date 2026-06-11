#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;
using ll = long long;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll N, string S) {
  set<char> se;
  size_t ma{};
  for (size_t i = 0; i != S.size(); ++i) {
    se.clear();
    string X = S.substr(0, i);
    string Y = S.substr(i, S.npos);
    sort(ALL(X));
    sort(ALL(Y));
    set_intersection(ALL(X), ALL(Y), inserter(se, se.end()));
    ma = max(ma,se.size());
  }
  cout << ma << endl;
}

int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  solve(N, S);
  return 0;
}
