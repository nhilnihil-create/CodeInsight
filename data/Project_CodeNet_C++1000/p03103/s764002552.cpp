#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N , M ; cin >> N >> M ; 
  vector<int> A(N) , B(N) ; 
  
  for(int i = 0 ; i< N ; i++){
    cin >> A.at(i) >> B.at(i) ; 
  }
  vector<pair<int , int >> AB(N) ; 
  for(int i = 0 ; i < N ; i++){
    AB.at(i) = make_pair(A.at(i) , B.at(i)) ; 
  }
  sort(AB.begin() , AB.end()) ; 
  
  long long ans = 0 ; 
  for(int i = 0 ; i < N ; i++){
    long long num_buy = min(M , AB.at(i).second) ; 
    ans += num_buy * AB.at(i).first ;
    M -= num_buy ; 
  }
  
  cout << ans << endl ; 
}