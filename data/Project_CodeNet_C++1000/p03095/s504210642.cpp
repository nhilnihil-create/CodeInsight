#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> vec(26, 0);
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    ++vec[c - 'a'];
  }

  ll ans = 1;
  for (int i = 0; i < 26; ++i)
    ans = (ans * (vec[i] + 1) ) % 1000000007;
  cout << ans - 1 << endl;
}
