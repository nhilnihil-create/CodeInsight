#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int f(int n) {
  if (n % 2 == 0) {
    return n / 2;
  } else {
    return 3 * n + 1;
  }
}

int main() {
  int s;
  cin >> s;
  vector<int> aa;
  for (int i = 1; i <= 1000000; i++) {
    if (i == 1) {
      aa.push_back(s);
      continue;
    }
    int cur = f(aa.back());
    if (find(aa.begin(), aa.end(), cur) != aa.end()) {
      cout << i << endl;
      break;
    }
    aa.push_back(cur);
  }
  return 0;
}
