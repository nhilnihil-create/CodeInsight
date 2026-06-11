#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  vector<int> abc(3);
  int sum = 0;
  rep(i, 3) {
    int x;
    cin >> x;
    abc.at(i) = x;
    sum += x;
  }
  sort(abc.rbegin(), abc.rend());
  int maxV = abc.at(0);
  int resultSum = (maxV * 3 % 2 == sum % 2) ? maxV * 3 : (maxV + 1) * 3;
  int res = (resultSum - sum) / 2;
  cout << res << endl;
  return 0;
}
