#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  if(N < 357) {
    cout << 0 << endl;
    return 0;
  }
  
  int ans = 0;
  string s = "357";
  while(stoi(s) <= N) {
    if(count(all(s),'3')>0 && count(all(s),'5')>0 && count(all(s),'7')>0) ans++;
    int k = s.size()-1;
    while(true) {
      if(s[k] == '3') {
        s[k] = '5';
        break;
      }
      if(s[k] == '5') {
        s[k] = '7';
        break;
      }
      if(s[k] == '7') {
        if(k > 0) k--;
        else {
          s = '3' + s;
          break;
        }
      }
    }
    for(int i=k+1; i<(int)(s.size()); i++) s[i] = '3';
  }
  cout << ans << endl;

}