#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, T;
  cin >> n >> T;
  int ans = 10000000;
  for(int i = 0; i < n; ++i){
    int c, t;
    cin >> c >> t;
    if(t <= T) ans = min(ans, c);
  }
  
  if(ans > 1000) cout << "TLE" << endl;
  else cout << ans << endl;
}