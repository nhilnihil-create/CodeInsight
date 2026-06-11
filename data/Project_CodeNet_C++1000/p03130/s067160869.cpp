#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<int> count(5, 0);
  int a;
  REP(i, 6) {
    cin >> a;
    ++count.at(a);
  }

  if (count.at(1) <= 2 && count.at(2) <= 2 && count.at(3) <= 2 &&
      count.at(4) <= 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
