#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

bool kaibun(int n) {
  string s = to_string(n);
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - i - 1]) return false;
  }
  return true;
}

int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) {
    if (kaibun(i)) ans++;
  }
  cout << ans << endl;
  return 0;
}