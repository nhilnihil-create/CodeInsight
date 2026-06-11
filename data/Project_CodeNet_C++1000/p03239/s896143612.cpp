#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, T;
  cin >> N >> T;
  
  int c[N], t[N];
  for (int i = 0; i < N; i++) {
    cin >> c[i] >> t[i];
  }
  
  int ans = 10000;
  for (int i = 0; i < N; i++) {
    if(t[i]<=T) ans = min(ans, c[i]);
  }
  
  if (ans==10000) cout << "TLE" << endl;
  else cout << ans << endl;
  
  return 0;
}