#include<bits/stdc++.h>
using namespace std ; 

int main(){
  long long N ; cin >> N ; 
  vector<long long> a(N) ; 
  for(long long i = 0 ; i < N ; i++){
    cin >> a.at(i) ; 
  }
  long long cnt = 0 ;  
  for(long long i = 0 ; i < N ;i++){
    if(a.at(i)%2 == 0 ){
      while(a.at(i)%2 == 0 ){
        a.at(i) /= 2 ; 
        cnt++ ; 
      }
      //cout << cnt << endl ; 
    }
  }
  cout << cnt << endl ; 
}