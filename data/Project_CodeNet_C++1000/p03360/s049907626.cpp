#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int a,b,c,k,i;
    cin>>a>>b>>c>>k;
    int x[3]={a,b,c};
    
    sort(x,x+3);
    
    for(i=1;i<=k;++i)
      {
          x[2]=x[2]*2;
      }
      int sum=x[0]+x[1]+x[2];
    cout<<sum;
    
   
         
}