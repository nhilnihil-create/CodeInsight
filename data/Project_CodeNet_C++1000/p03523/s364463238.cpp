#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

vector<string> expected;
const string ALL = "AKIHABARA";

void dfs(string current, int index) {
  if (index == 9) {
    expected.push_back(current);
    return;
  }

  if (ALL.at(index) == 'A') {
    dfs(current, index + 1);
  }
  dfs(current + ALL.at(index), index + 1);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  dfs("", 0);

  if (find(expected.begin(), expected.end(), S) != expected.end()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
