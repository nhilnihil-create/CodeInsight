#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int i,j,k,ans,n,a,b,c,aa,bb,cc,amax,bmax,cmax;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>a>>b>>c;
    if(i==0){amax=a;bmax=b;cmax=c;}
    else
    {
      aa=a+max(bmax,cmax);
      bb=b+max(amax,cmax);
      cc=c+max(amax,bmax);
      amax=aa;
      bmax=bb;
      cmax=cc;
    }
    
  }
  ans=max(max(amax,bmax),cmax);
  cout<<ans<<endl;
  
  
}