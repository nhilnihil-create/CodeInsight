#include <iostream>
using namespace std;

int main(){
int a,b;
cin>>a>>b;
a=a*3+b;
  if(a%2==0){
  cout<<a/2<<endl;
  }
  else{
  cout<<(a-1)/2<<endl;
  }

return  0;
}