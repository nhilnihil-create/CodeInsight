#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 1; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

bool nine = true;
int ans;

int main() {
  string n;
  cin >> n;
  rep (i, n.size()) {
    if (n[i] != '9') nine = false;
  }
  if (nine) {
    ans = n[0] - '0' + (n.size()-1) * 9;
  } else {
    ans = n[0] - '1' + 9 * (n.size()-1);
  }
  cout << ans << endl;
  return 0;
}
