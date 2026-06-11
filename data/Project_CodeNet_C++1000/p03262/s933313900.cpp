#include<bits/stdc++.h>
using namespace std ;

int main(){
  long long N , X ;
  cin >> N >> X ; 
  vector<long long> x(N+1) ; 
  
  for(int i = 0 ; i < N ; i++){
    cin >> x.at(i) ; 
  }
  x.at(N) = X ; 
  sort(x.begin(),x.end()) ; 
  
  vector<long long> y(N) ; 
  
  for(int i = 0 ; i < N ; i++){
    y.at(i) = x.at(i+1) - x.at(i) ; 
    //cout << y.at(i) << endl  ;
  }
  
  long long ans = gcd(y.at(0) , y.at(0)) ; 
  for(int i = 0 ;  i < N ; i++){
    ans = gcd(ans , y.at(i) ) ; 
  }

  cout << ans << endl ; 
  
}