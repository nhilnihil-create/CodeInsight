#include <string>
#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

int n, q;
string a[200005], b[200005], c, d, st;

int main() {
  cin >> n >> q >> st;
  
  for (int i = 0; i < q; ++i) {
    cin >> a[i] >> b[i];
  }

  int l = -1, r = n;
  for (int i = q-1; i >= 0; --i) {
    c = a[i];
    d = b[i];

    if (d[0] == 'L') {
      if (st[l + 1] == c[0]) {
        ++ l;
      }

      if (r < n && st[r] == c[0]) {
        ++ r;
      }
    } else {
      if (st[r - 1] == c[0]) {
        -- r;
      }

      if (l >= 0 && st[l] == c[0]) {
        -- l;
      }
    }
  }
  
  cout << r - l - 1 << endl;
  return 0;
}

