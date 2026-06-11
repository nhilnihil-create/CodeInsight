#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  rep(i,h)rep(j,w) {
    if (s[i][j] == '#') continue;
    else {
      int cnt = 0;
      if (i+1 < h && s[i+1][j] == '#') cnt++;
      if (0<= i-1 && s[i-1][j] == '#') cnt++;
      if (j+1 < w && s[i][j+1] == '#') cnt++;
      if (0 <= j-1 && s[i][j-1] == '#') cnt++;
      if (i+1 < h  && j+1 < w && s[i+1][j+1] == '#') cnt++;
      if (i+1 < h && 0 <= j-1 && s[i+1][j-1] == '#') cnt++;
      if (0 <= i-1 && j+1 < w && s[i-1][j+1] == '#') cnt++;
      if (0 <= i-1 && 0 <= j-1 && s[i-1][j-1] == '#') cnt++;
      s[i][j] = char(cnt + '0');
    } 
  }

  rep(i,h) cout << s[i] << endl;
  return 0;
}
