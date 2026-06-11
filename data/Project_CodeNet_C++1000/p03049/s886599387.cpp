#include <bits/stdc++.h>

//#include <atcoder/all>

using namespace std;
// using namespace atcoder;
using ll = long long;

int main() {
  int n;
  int ba = 0, _a = 0, b_ = 0;
  int in = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for (int i = 0; i + 1 < (int)s.size(); i++) {
      if (s[i] == 'A' && s[i + 1] == 'B') in++;
    }

    if (s.front() == 'B' && s.back() == 'A') {
      ba++;
    } else {
      if (s.front() == 'B') {
        b_++;
      }
      if (s.back() == 'A') {
        _a++;
      }
    }
  }

  if (_a == 0 && b_ == 0) {
    cout << in + max(ba - 1, 0) << endl;
  } else {
    cout << in + ba + min(_a, b_) << endl;
  }
}