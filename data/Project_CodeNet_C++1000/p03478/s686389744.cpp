#include<bits/stdc++.h>
using namespace std;
int dig(int n)
{
  int t=n;
  int r;
  int sum=0;
  while(t!=0)
  {
    r=t%10;
    sum=sum+r;
    t=t/10;
    
    
      
  }
  return sum;
  
}
int main()
{
  int z;
  int n,a,b;
  cin>>n>>a>>b;
  int res=0;
  for(int i=1;i<=n;i++)
    

      {
        z=dig(i);
        if(z>=a && z<=b)
        {
          res=res+i;

          
        }
        
        
        
      }
  cout<<res<<endl;
  
  
  
}