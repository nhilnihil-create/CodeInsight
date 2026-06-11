#include<iostream>
using namespace std;
int main(){
  int a;
  cin>>a;
  int b[4];
  for(int i=0;i<4;i++){
    b[i]=a%10;
    a=a/10;
  }
  
  if((b[0]==b[1]&&b[1]==b[2])||(b[1]==b[2]&&b[2]==b[3]))
     cout<<"Yes";
  else if(b[0]==b[1]&&b[1]==b[2]&&b[2]==b[3])
    cout<<"Yes";
  else
    cout<<"No";
  return 0;
}
