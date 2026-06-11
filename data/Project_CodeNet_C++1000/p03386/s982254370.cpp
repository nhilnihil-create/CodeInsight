#include<bits/stdc++.h>
using namespace std ;

int main(){
  int A ,B , K ; 
  cin >> A >> B >> K ; 
  
  for(int i = A ; i <= B ; i++){
    if(i >= A+K || B < i ){
     
    }
    else{
      cout << i << endl ; 
    }
  }
  
  for(int i = B-K+1 ; i <= B ; i++ ){
        if(i > B || A+K > i  ){
       
    }
    else{
      cout << i << endl ; 
    }
  }
  
}