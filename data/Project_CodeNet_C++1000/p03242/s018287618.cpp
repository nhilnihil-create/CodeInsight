#include<iostream>
using namespace std;
int main(){
  int a;
  cin>>a;
  int b[3];
  for(int i=0;i<3;i++){
    b[i]=a%10;
    a=a/10;
    if(b[i]==1)
      b[i]=9;
    else
      b[i]=1;
  }
  
  for(int i=2;i>=0;i--){
    cout<<b[i];
  }
  return 0;
}
