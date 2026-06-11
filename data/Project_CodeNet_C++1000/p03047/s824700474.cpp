#include<iostream>
using namespace std;
main()
{
  int n,k;
  cin>>n>>k;
  if(k>n)
    cout<<0<<endl;
  else
    cout<<n-k+1<<endl;
}