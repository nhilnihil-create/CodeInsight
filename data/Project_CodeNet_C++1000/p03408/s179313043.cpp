#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N ; 
  cin >> N ; 
  vector<string> s(N) ; 
  map<string , int> MAP ; 
  for(int i = 0 ; i < N ; i++){
    cin >> s.at(i) ; 
    MAP[s.at(i)]++ ; 
  }
  
  int M ; 
  cin >> M ; 
  vector<string> t(M) ; 
  for(int i = 0 ;i < M ; i++){
    cin >> t.at(i) ; 
    MAP[t.at(i)]--  ;
  }
  
  int cnt = 0 ; 
  for(auto p : MAP){
    cnt = max(cnt , p.second) ; 
  }
  cout << cnt <<  endl ; 
}