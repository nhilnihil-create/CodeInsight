#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> l(m);
  vector<int> r(m);
  rep(i, m) cin >> l[i] >> r[i];
  int lm = l[0];
  int rm = r[0];
  rep(i, m) {
    if (lm < l[i]) lm = l[i];
    if (rm > r[i]) rm = r[i];
  }
  if (rm - lm + 1 < 0)
    cout << 0 << endl;
  else
    cout << rm - lm + 1 << endl;
  return 0;
}