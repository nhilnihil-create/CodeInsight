#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n, m, ans;
string x;

int main() {
  map<string, int> card;
  cin >> n;
  ans = 0;
  rep (i, n) {
    cin >> x;
    card[x]++;
  }
  cin >> m;
  rep (i, m) {
    cin >> x;
    card[x]--;
  }
  for (auto i = card.begin(); i != card.end(); ++i) {
    ans = max(ans, i->second);
  }
  cout << ans << endl;
  return 0;
}
