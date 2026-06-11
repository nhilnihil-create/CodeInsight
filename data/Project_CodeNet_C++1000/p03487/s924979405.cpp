#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ; 
  map<long long , long long>  M ; 
  for(int i = 0 ; i < N ; i++){
    int a ; 
    cin >> a ;
    M[a]++ ; 
    
  }
  long long cnt = 0 ; 
  for(auto p : M ){
    if(p.first > p.second ) cnt += p.second ;
    else cnt += p.second - p.first ; 
  }
  cout << cnt << endl ;
}