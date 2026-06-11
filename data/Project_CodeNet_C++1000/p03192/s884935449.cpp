#include<iostream>
using namespace std;
int main(){
  int a,c=0;
  int i,b[4];
  cin>>a;
  for(i=0;i<4;i++){
    b[i]=a%10;
    a=a/10;
    if(b[i]==2)
      c++;
  }
  
  cout<<c;
  return 0;
}
  
