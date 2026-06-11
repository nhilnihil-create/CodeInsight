#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  int ml = 1, mr = n;
  rep(i, m) {
    int l, r;
    cin >> l >> r;
    ml = max(ml, l);
    mr = min(mr, r);
  }
  if (mr < ml) {
    cout << 0 << endl;
  } else {
    cout << mr - ml + 1 << endl;
  }
}
