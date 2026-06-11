#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ; 
  int Y ; 
  cin >> Y ;
  
  for(long long i = 0 ; i <= N ; i++){
    for(long long j = 0 ; j <= N ; j++){
      long long k = N - i - j ; 
      if(k*1000 + j*5000 + i*10000 == Y && k >= 0 && i >= 0 && j >= 0){
        cout << i << " " << j << " " << k << endl;
        return 0 ; 
      }
    }
  }
  
  cout << -1 << " " << -1 << " " << -1 << endl ; 
}