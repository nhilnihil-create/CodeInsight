#include <bits/stdc++.h>
using namespace std;

int main(void){
    
  int N,T,ans=10000,c,t;
  cin >> N >> T;
  
  for(int i=0;i<N;i++){
      cin >> c >> t;
      if(t <= T && c < ans){
          ans = c;
      }
  }
  
  if(ans == 10000) cout << "TLE" << endl;
  else cout << ans << endl;
}