#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n, T;
  cin >> n >> T;
  
  int ans = 1001;
  REP(i,n) { 
    int c, t;
    cin >> c >> t;
    if (t <= T) ans = min(ans,c);
  }
 
  if (ans == 1001) cout << "TLE" << endl;
  else cout << ans << endl;
  
}