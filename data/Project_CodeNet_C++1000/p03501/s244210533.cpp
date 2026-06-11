#include<iostream>
using namespace std;
int main()
{
  int n,a,b;
  cin>>n>>a>>b;
  if(n*a<b)
    cout<<a*n;
  else
    cout<<b;
}