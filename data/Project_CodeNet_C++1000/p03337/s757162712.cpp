#include<iostream>

using namespace std;

int main(void)
{
  int a,b;  cin>>a>>b;
  int r1=a+b,r2=a-b,r3=a*b;
  
  if((r1>=r2)&&(r1>=r3)){cout<<r1<<endl;}
  else if((r2>=r1)&&(r2>=r3)){cout<<r2<<endl;}
  else if((r3>=r1)&&(r3>=r2)){cout<<r3<<endl;}
  
  return 0;
}
