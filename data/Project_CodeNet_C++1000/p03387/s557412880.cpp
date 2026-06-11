#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{ 
  int a[3],i,j,k,n,ans;
  for(i=0;i<3;i++){cin>>a[i];}
  sort(a,a+3);
  ans=0;
 while(a[1]!=a[2]){ans++;a[0]++;a[1]++;}
  
  n=a[2]-a[0];
  ans+=n/2;
  if(n%2==1)ans+=2;
  cout<<ans;
  
  
}