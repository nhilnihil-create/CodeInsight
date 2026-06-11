#include<iostream>
using namespace std;
int main()
{
  	int A,B,N,x;
  cin>>N>>A>>B;
  x=A*N;
  if(x>=B)
    cout<<B;
  else
    cout<<x;
}