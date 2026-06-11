#include<bits/stdc++.h>
using namespace std ;


int main(){
  int N , K ; cin >> N >> K ; 
  vector<long long> h(N) ; 
  for(int i = 0 ; i < N ; i++) cin >> h.at(i) ; 
  
  sort(h.begin(),h.end()) ; 
  
  long long ans = 10e9 ;
  for(int i = 0 ; i <= N-K ; i++){
    ans = min(ans , abs(h.at(i)-h.at(i+K-1))) ; 
  }
  
  cout << ans << endl; 
}