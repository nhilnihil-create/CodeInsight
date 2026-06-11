#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  string s[3];
  rep(i, 3) {
    cin >> s[i];
  }

  cout << s[0][0] << s[1][1] << s[2][2] << endl;
  
  return 0;
}