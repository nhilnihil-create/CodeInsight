#include<iostream>

using namespace std;

int main(void)
{
  int a,b,c,d; cin>>a>>b>>c>>d;
  int r1,r2;
  
  r1=a>b?b:a;
  r2=c>d?d:c;
  
  cout<<r1+r2<<endl;
  return 0;
}