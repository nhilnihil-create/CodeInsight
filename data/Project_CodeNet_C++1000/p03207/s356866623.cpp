#include<bits/stdc++.h>
using namespace std ;


int main(){
  int N ; 
  cin >> N ; 
  vector<int> P(N) ; 
  for(int i = 0 ; i < N ;i++){
    cin >> P.at(i) ; 
  }
  
  sort(P.begin(),P.end());
  reverse(P.begin(),P.end());
  
  int ans = 0 ; 
  
  for(int i = 0 ; i < N ; i++){
    if(i == 0 ) P.at(i) /= 2 ; 
    ans += P.at(i) ; 
  }
  
  cout << ans << endl ; 
  
}