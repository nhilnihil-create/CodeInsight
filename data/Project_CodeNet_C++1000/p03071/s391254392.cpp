#include <iostream>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  
  if(a==b){
    cout<<a*2;
    
  }
  
  else{
    int c=max(a,b);  
    cout<<c+c-1;
    
  }
  return 0;
}
