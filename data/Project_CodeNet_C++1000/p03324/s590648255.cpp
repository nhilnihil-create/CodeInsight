#include <iostream>
using namespace std;
int main (){
  int a, b, x;
  cin>>a>>b;
  if(a==0){
    a=1;
  }else if(a==1){
    a=100;
  }else{
    a=10000;
  }
  if(b==100){
    x=b*a+a;
  }else{
    x=a*b;
  }
  cout<<x<<endl;
  return 0;
}
