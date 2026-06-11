#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N , X ; 
  cin >> N >> X ; 
  vector<int> m(N) ; 
  int cnt = 0 ; 
  for(int i =0 ; i < N ; i++){
    cin >> m.at(i) ; 
    cnt+= m.at(i) ; 
  }
  X -= cnt ; 
  
  sort(m.begin(),m.end()) ;
  
  cout << N + X/m.at(0) << endl ; 
  
}