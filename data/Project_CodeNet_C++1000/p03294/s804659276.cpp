#include<bits/stdc++.h>
using namespace std ;

int main(){
  long long N ; 
  cin >> N ; 
  vector<long long> a(N) ; 
  for(int i = 0 ; i < N ; i++) cin >> a.at(i) ; 


  long long ans = 0 ; 
  for(int i = 0 ; i < N ; i++){
    ans += (a.at(i)-1) ; 
  }
  //cout << cnt << endl;
  cout << ans << endl; 
}