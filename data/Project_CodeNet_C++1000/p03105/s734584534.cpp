#include <iostream>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  
  int k=b/a;
  if(k>=c){
    cout<<c;
  }
  else 
    cout<<k;
  return 0;
}