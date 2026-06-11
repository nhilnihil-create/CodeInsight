#include <iostream>
#include <string>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(string n) {
  for (auto &c: n) {
    if (c == '9') c = '1';
    else c = '9';
  }
  cout << stoi(n) << endl;
}

int main() {
  string n;
  cin >> n;
  solve(move(n));
  return 0;
}
