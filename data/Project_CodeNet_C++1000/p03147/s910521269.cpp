#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ; 
  vector<int> h(N+1) ; 
  int cnt = 105 ; 
  for(int i = 1 ; i < N+1 ; i++ ){
    cin >> h.at(i) ; 
    cnt = min(cnt , h.at(i)) ; 
  }
  h.at(0) = cnt ; 
  
  int ans = 0 ; 
  for(int i = 1 ; i < N+1 ; i++){
    if(h.at(i) > cnt && h.at(i) -  max(cnt , h.at(i-1)) > 0){
      ans += h.at(i) -  max(cnt , h.at(i-1)) ; 
    }
  }
  cout << ans + cnt<< endl ; 
}