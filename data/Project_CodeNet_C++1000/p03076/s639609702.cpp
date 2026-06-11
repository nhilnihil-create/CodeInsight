
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    int ans=0;
    int min=INT_MAX;
    if(a%10!=0)
   {
       if(a%10<min)
       min=a%10;
        a/=10;
    a++;
    a*=10;
   }
    if(b%10!=0)
   {
       if(b%10<min)
       min=b%10;
       b/=10;
    b++;
    b*=10;
   }
    if(c%10!=0)
   {
       if(c%10<min)
       min=c%10;
         c/=10;
    c++;
    c*=10;
   }
      if(d%10!=0)
   {
       if(d%10<min)
       min=d%10;
      d/=10;
    d++;
    d*=10;
   }
      if(e%10!=0)
   {
       if(e%10<min)
       min=e%10;
        e/=10;
    e++;
    e*=10;
   }
   ans=(a+b+c+d+e);
 if(min==INT_MAX)
    cout<<ans;
    else
    cout<<ans-(10-min);
}
