#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int n,d,a[11],r;
  cin>>r>>d>>a[0];
  for(int i=1;i<=10;i++)
  {
    a[i]=a[i-1]*r-d;
    cout<<a[i]<<endl;
    
  }
  
  return 0;
}