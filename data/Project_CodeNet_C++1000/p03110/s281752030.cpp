#include <bits/stdc++.h>
using namespace std;


  
int main(){

 
  int n;
  cin>>n;
  
  double answer=0;
  
  for (int i=0;i<n;i++){
    double number;
    string text;
    cin>>number>>text;
    
    if (text=="JPY"){
      answer+=number;}
    
    else {
      answer+=380000.0*number;
    }
    
  }
  
  cout<<answer<<endl;
  
      
      
      
  

  
}
  













