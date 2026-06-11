#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int H, W; cin >> H >> W;
  vector<string> s(H);
  rep(i, H) cin >> s[i];
  
  rep(i, H) rep(j, W) {
    if(s[i][j] == '#') {
      bool t = false;
      if((i>0&&s[i-1][j]=='#') || (j>0&&s[i][j-1]=='#') || (i<H-1&&s[i+1][j]=='#') || (j<W-1&&s[i][j+1]=='#'))
        t = true;
      if(!t) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  
}
