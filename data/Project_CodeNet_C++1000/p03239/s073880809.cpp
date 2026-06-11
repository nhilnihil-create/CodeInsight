#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N , T ; 
  cin >> N >> T ; 
  int ans = 1005 ;
  int cnt = 0 ; 
  
  for(int i = 0 ; i < N ;i++){
    int c, t ; 
    cin >> c >> t ; 
    if(t <= T){
      ans = min(ans,c) ; 
      cnt++ ; 
    }
    
  }
  if( cnt == 0 ){
    cout << "TLE" << endl ; 
    return 0 ; 
  }
  cout << ans << endl ; 
  
}