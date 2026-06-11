#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string s, ans;
  int w;
  cin >> s >> w;
  for (int i = 0; i < s.size(); i+=w) {
    ans += s[i];
  }
  cout << ans << endl;
  return 0;
}