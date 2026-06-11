#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()
#define let auto const

int main() {
  i64 N;
  cin >> N;
  string s;
  cin >> s;
  i64 Q;
  cin >> Q;

  rep(q, 0, Q) {
    i64 K;
    cin >> K;
    i64 D = 0, M = 0;
    i64 now = 0;
    i64 ans = 0;
    rep(i,0,N) {
      if(s[i] == 'D') {
        D++;
      }
      else if(s[i] == 'M') {
        M++;
        now += D;
      }
      else if(s[i] == 'C') {
        ans += now;
      }
      if(i - K + 1 >= 0) {
        if(s[i - K + 1] == 'D') {
          D--;
          now -= M;
        }
        else if(s[i - K + 1] == 'M') {
          M--;
        }
      }
    }
    cout << ans << endl;
  }
}
