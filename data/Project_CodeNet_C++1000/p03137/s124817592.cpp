#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N , M ; 
  cin >> N >> M ; 
  vector<int> X(M) ; 
  
  for(int i = 0 ; i < M ; i++) cin >> X.at(i) ; 
  sort(X.begin(),X.end());
  
  vector<long long> S(M) ; 
  for(int i = 1 ; i < M ; i++){
    S.at(i) = X.at(i) - X.at(i-1) ; 
    //cout << S.at(i) << endl; 
  }
  
  sort(S.begin(),S.end()) ; 
  reverse(S.begin(),S.end()) ; 
  long long ans = 0 ; 
  for(int i = N-1 ; i < M ; i++){
    ans += S.at(i) ;  
  }
  cout << ans << endl ; 
}