#include <iostream>
#define long long ll
using namespace std;

int main() {
  int i,n,y,x,s;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
  	cin>>a[i];

  x=a[0];
  s=a[0];
  
  for(i=1;i<n;i++)
  { 
    if(a[i]>x)
    {
		y=a[i]-x;
      s=s+y;
    } 
    x=a[i];
  }
  cout<<s;
  
  
  return 0;
}
  
