#include <bits/stdc++.h>

using namespace std;

int tv[33][101010];

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> s(n), t(n), ch(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> t[i] >> ch[i];
    ch[i]--;
  }
  for (int i = 0; i < n; i++) {
    tv[ch[i]][s[i]]++;
    tv[ch[i]][t[i]]--;
  }
  int use = 0, fr = 0;
  for (int i = 0; i < 100010; i++) {
    for (int j = 0; j < c; j++) {
      if (fr == 0 && tv[j][i] == 1) {
        use++;
      } else if (0 < fr && tv[j][i] == 1) {
        fr--;
        use++;
      }
    }
    for (int j = 0; j < c; j++) {
      if (tv[j][i] == -1) {
        fr++;
        use--;
      }
    }
  }
  cout << fr << endl;

  return 0;
}