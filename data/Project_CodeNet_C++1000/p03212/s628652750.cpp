#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> _753;

void generate_753() {
  for (int d = 3; d <= 9; ++d) {
    rep(bit, pow(3, d)) {
      int b = bit;
      bool _7 = false, _5 = false, _3 = false;
      int x = 0;
      rep(i, d) {
        x *= 10;
        switch (b % 3) {
          case 0:
            x += 7;
            _7 = true;
            break;
          case 1:
            x += 5;
            _5 = true;
            break;
          case 2:
            x += 3;
            _3 = true;
            break;
          default: break;
        }
        b /= 3;
      }
      if (_7 && _5 && _3) _753.push_back(x);
    }
  }
  sort(_753.begin(), _753.end());
  return;
}

int main() {
  generate_753();
  int n;
  cin >> n;
  int ans = upper_bound(_753.begin(), _753.end(), n) - _753.begin();
  cout << ans << endl;
  return 0;
}