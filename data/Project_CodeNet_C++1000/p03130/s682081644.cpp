#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 998244353;

int main() {
  int count[4] = {};
  rep(i, 3) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    count[a]++;
    count[b]++;
  }
  sort(count, count + 4);
  if (count[0] == 1 && count[1] == 1 && count[2] == 2 && count[3] == 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}