#include<iostream>
using namespace std;
int main()
{
  int c=0,N;
  cin>>N;
  while(N>0)
  {
    if(N%10==2)
      c++;
    N/=10;
  }
  cout<<c<<endl;
  return 0;
}