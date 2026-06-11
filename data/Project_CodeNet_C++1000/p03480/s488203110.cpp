#include <iostream>

using namespace std;
typedef long long ll;
string s;

void solve () {
  ll maxK0 = s.size();
  ll maxK1 = s.size();
  for (ll i=0;i<s.size();i++) {
    if (s[i] == '1') {
      maxK0 = min(maxK0, max<ll>(i, s.size() - i - 1));
    } else {
      maxK1 = min(maxK1, max<ll>(i, s.size() - i - 1));
    }
  }
  cout << max(maxK0, maxK1) << endl;
}

int main() {
  cin >> s;
  solve();
}
