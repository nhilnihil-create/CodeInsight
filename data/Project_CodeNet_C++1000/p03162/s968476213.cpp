#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N  ; 
  vector<vector<int>> A(N , vector<int>(3)) ;
  vector<vector<int>> dp(N , vector<int>(3)) ; 
  
  for(int i = 0 ; i < N ; i++){
    int a , b  ,c ;
    cin >> a >> b >> c ;
    A.at(i).at(0) = a ;
    A.at(i).at(1) = b ;
    A.at(i).at(2) = c ;    
  }
  for(int i = 0 ; i < 1 ; i++){
    for(int j = 0 ; j < 3 ; j++){
    	dp.at(i).at(j) = A.at(i).at(j);
    }
  }
  
  for(int i = 1 ; i < N ; i++){
    	dp.at(i).at(0) = max(dp.at(i-1).at(1)+A.at(i).at(0),dp.at(i-1).at(2)+A.at(i).at(0));
    	dp.at(i).at(1) = max(dp.at(i-1).at(0)+A.at(i).at(1),dp.at(i-1).at(2)+A.at(i).at(1));
    	dp.at(i).at(2) = max(dp.at(i-1).at(0)+A.at(i).at(2),dp.at(i-1).at(1)+A.at(i).at(2));      
    
  }
  
  cout << max(dp.at(N-1).at(0),max(dp.at(N-1).at(1),dp.at(N-1).at(2))) ; 

}