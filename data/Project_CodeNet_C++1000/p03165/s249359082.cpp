#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  string s, t;
  cin >> s >> t;

  vector<vector<ll>> dp(s.size(), vector<ll>(t.size(), 0));

  dp.at(0).at(0) = 0;
  if (s.at(0) == t.at(0)) {
    dp.at(0).at(0) = 1;
  }

  for (long long i = 1; i < s.size(); i++) {
    if (dp.at(i).at(0) == 0 && s.at(i) == t.at(0)) {
      dp.at(i).at(0)++;
    } else {
      dp.at(i).at(0) = dp.at(i - 1).at(0);
    }
  }
  for (long long j = 1; j < t.size(); j++) {
    if (dp.at(0).at(j) == 0 && t.at(j) == s.at(0)) {
      dp.at(0).at(j)++;
    } else {
      dp.at(0).at(j) = dp.at(0).at(j - 1);
    }
  }

  for (long long i = 1; i < s.size(); i++) {
    for (long long j = 1; j < t.size(); j++) {
      if (s.at(i) == t.at(j)) {
        dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
      } else {
        if (dp.at(i).at(j - 1) > dp.at(i - 1).at(j)) {
          dp.at(i).at(j) = dp.at(i).at(j - 1);
        } else {
          dp.at(i).at(j) = dp.at(i - 1).at(j);
        }
      }
    }
  }

  string ans = "";
  ll i = s.size() - 1, j = t.size() - 1;

  while (i > 0 && j > 0) {
    if (dp.at(i).at(j) == dp.at(i - 1).at(j)) {
      i--;
    } else if (dp.at(i).at(j) == dp.at(i).at(j - 1)) {
      j--;
    } else {
      ans = s.at(i) + ans;
      i--;
      j--;
    }
  }

  if (dp.at(i).at(j) != 0) {
    if (i == 0) {
      ans = s.at(0) + ans;
    } else {
      ans = t.at(0) + ans;
    }
  }
  cout << ans << endl;
}
