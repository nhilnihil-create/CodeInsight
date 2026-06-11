#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int i,a[5],b[5],ans=650,sum,aa=0;
  for(i=0;i<5;i++)
  {
    cin>>a[i];
  }
  for(i=0;i<5;i++)
  {
    b[i]=a[i]%10;
    if(b[i]==0)b[i]=10;
    if(ans>b[i])ans=b[i],sum=i;
    
    a[i]=a[i]+10-b[i];
  }
  for(i=0;i<5;i++)
  {
    aa+=a[i];
    if(i==sum){aa+=b[i];}
  }
  aa-=10;
  cout<<aa<<endl;
  
  
}