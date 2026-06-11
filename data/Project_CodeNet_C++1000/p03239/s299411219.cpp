#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,T,ans=1001; cin >> N >> T;
  vector<int> c(110),t(110);
  for(int i=1; i<=N; i++) {
    cin >> c[i] >> t[i];
  }
  
  for(int i=1; i<=N; i++) {
    if(t[i]<=T) ans= min(ans,c[i]);
  }
  if(ans==1001) cout << "TLE" << endl;
  else cout << ans << endl;
}