#include<iostream>
using namespace std;
int main(void)
{
  int i,j,k,n,t[100001],x[100001],y[100001],z[100001];
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>t[i+1]>>x[i+1]>>y[i+1];
  }
  t[0]=0;
  x[0]=0;
  y[0]=0;
           
  for(i=0;i<=n;i++)
  {
    z[i]=x[i]+y[i];
  }
  for(i=0;i<n;i++)
  {
    j=abs(z[i+1]-z[i]);
    k=t[i+1]-t[i];
    if(k%2!=j%2||j>k)
    {
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}