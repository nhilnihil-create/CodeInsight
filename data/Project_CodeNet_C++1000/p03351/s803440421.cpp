#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  
  if( (0 <= a-c && a-c <= d) || (0 <= c-a && c-a <= d) ){  
    
  cout << "Yes" << endl; 

  }

  else if( (0 <= b-a && b-a <= d) && (0 <= b-c && b-c <= d) ){
    
  cout << "Yes" << endl;  
    
  }
 
  else if( (0 <= b-a && b-a <= d) && (0 <= c-b && c-b <= d) ){
    
  cout << "Yes" << endl;  
    
  }  
  
  else if( (0 <= a-b && a-b <= d) && (0 <= b-c && b-c <= d) ){
    
  cout << "Yes" << endl;  
    
  }
          
  else if( (0 <= a-b && a-b <= d) && (0 <= c-b && c-b <= d) ){
                                      
  cout << "Yes" << endl;  
    
  }
          
  
  else{
    
  cout << "No" << endl;
    
  }
  
}
  

    
