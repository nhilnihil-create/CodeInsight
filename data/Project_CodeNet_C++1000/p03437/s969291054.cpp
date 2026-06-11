#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a,long long int b)
{
    if(b==0)
       return a;
       
    else
       return gcd(b,a%b);
}

int main()
{
  
    long long int x,i,y,ans=0;
    scanf("%lld%lld",&x,&y);
    if(x==y ||((x>y) && (gcd(x,y)==y)))
       printf("-1");
    
    else
    {
          ans=(x*y)/(gcd(x,y));
          printf("%lld",ans-x);
         
    }
   
     
    
}