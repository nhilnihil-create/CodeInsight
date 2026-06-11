#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  vector<int> abc(3);
  rep(i, 3) cin >> abc.at(i);
  sort(abc.rbegin(), abc.rend());
  int res = 0;
  while (abc.at(0) != abc.at(1) || abc.at(1) != abc.at(2)) {
    if (abc.at(0) > abc.at(1)) {
      abc.at(1)++;
      abc.at(2)++;
      res++;
    } else if (abc.at(0) > abc.at(2)) {
      abc.at(2) += 2;
      res++;
    } else {
      abc.at(0)++;
      abc.at(1)++;
      res++;
    }
  }
  cout << res << endl;
  return 0;
}
