#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  int b = 0, r = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') b++;
    else r++;
  }
  cout << min(r, b) * 2 << endl;
  return 0;
}