#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int r, b;
  r = b = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') r++;
    else b++;
  }
  cout << (r > b ? "Yes" : "No") << endl;
  return 0;
}