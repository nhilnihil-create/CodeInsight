#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int a,b,c,d,e,k;
  cin>>a>>b>>c>>d>>e>>k;
  if(max({a,b,c,d,e})-min({a,b,c,d,e}) > k)
  {
    cout<<":(";
  }
  else
  {
	cout<<"Yay!";
  }
  
  return 0;
} 