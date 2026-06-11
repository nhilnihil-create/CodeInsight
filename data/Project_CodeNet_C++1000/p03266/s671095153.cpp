#include <bits/stdc++.h>
using namespace std;


int main(){


  int n,k;
  cin>>n>>k;
  
  long long answer=0;
  
  

  if (k%2!=0){
    answer=pow(n/k,3);
  }
  
  else {
    answer=pow(n/k,3)+pow((n+(k/2))/k,3);
  }
  
  cout<<answer<<endl;
  
  
    
      
   
    
  
  
  

    
    
    

  
}