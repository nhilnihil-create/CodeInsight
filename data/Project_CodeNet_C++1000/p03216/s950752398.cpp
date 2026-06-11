#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    ll m = 0, c = 0, dmc = 0, ans = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
      while (j < n && j - i < k) {
        if (s[j] == 'M') {
          m++;
        } else if (s[j] == 'C') {
          c++;
          dmc += m;
        }
        j++;
      }
      if (s[i] == 'D') {
        ans += dmc;
      }
      if (i == j) {
        j++;
      } else {
        if (s[i] == 'M') {
          m--;
          dmc -= c;
        } else if (s[i] == 'C') {
          c--;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}