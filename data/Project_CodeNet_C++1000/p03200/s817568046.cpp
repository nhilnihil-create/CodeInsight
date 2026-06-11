#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

string s;
ll ans;
int a[N], ps[N];

void solve() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'B') a[i+1] = 1;
    else a[i+1] = 0;
  }
  for (int i = 1; i <= s.size(); i++) {
    ps[i] = ps[i-1] + a[i];
  }
  ans = 0;
  for (int i = 1; i <= s.size(); i++) {
    if (!a[i]) ans += ps[i];
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}