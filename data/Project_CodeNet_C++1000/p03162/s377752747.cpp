#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int i,ans,n,a,b,c,aa,bb,cc,amax=0,bmax=0,cmax=0;
  cin>>n;
  
  for(i=0;i<n;i++)
  {
    cin>>a>>b>>c;
    aa=a+max(bmax,cmax);
    bb=b+max(amax,cmax);
    cc=c+max(amax,bmax);
    amax=aa;
    bmax=bb;
    cmax=cc;
  }
  ans=max({amax,bmax,cmax});
  cout<<ans<<endl;
  
  
}