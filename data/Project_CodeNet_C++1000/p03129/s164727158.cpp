#include<iostream>
using namespace std ;

int main()
{
  int N,K ;
  cin>>N>>K ;
  
  if(K>(N+1)/2) cout<<"NO"<<endl ;
  else cout<<"YES"<<endl ;
  
  return 0 ;
}