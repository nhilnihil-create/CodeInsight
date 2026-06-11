#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
const int INF{int(1e9)};

int main()
{
  int N, T;
  cin >> N >> T;
  
  int c, t;
  int ans{INF};
  rep(i, N) {
      cin >> c >> t;
    if (t<= T && c < ans) {
      ans = c;
    }
  }
 if (ans == INF) {
   cout << "TLE" << endl;
 }
  else cout << ans << endl;
}