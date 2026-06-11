#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N , K ; cin >> N >> K ; 
  double ans = 0 ; 
  for(int i = 1 ; i <= N ; i++){
    double P = 1 ; 
    int x = i ; 
    while(x < K){
      P *= 0.5 ; 
      x *= 2 ; 
    }
    ans += P/N ; 
  }
  
  cout << fixed << setprecision(13) << ans << endl;

}