#include<iostream>

using namespace std;

int main(void)
{
  int a,b,c,d; cin>>a>>b>>c>>d;
  int sum1=a+b,sum2=c+d;
  
  if(sum1==sum2){puts("Balanced");}
  else if(sum1>sum2){puts("Left");}
  else{puts("Right");}
  
  return 0;
}