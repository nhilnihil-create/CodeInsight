#include<bits/stdc++.h>
using namespace std;
long long ten(long long x)
{
    long long res=0;
    while(x>0)
    {
        res+=x%10;
        x/=10;
    }
    return res;
}
long long num[1000000];
int main()
{
   int n;
   while(~scanf("%d",&n))
  {
      long long ans=0,temp=1;
      for(int i = 1;i<=n;i++)
      {

          long long n1=ans+temp*10;
          long long n2=ans+temp;//cout<<n1<<" "<<n2<<endl;
          if(n1*ten(n2)<=n2*ten(n1))
          {
              ans=n1;temp*=10;
          }
          else
          {
              ans=n2;
          }
          printf("%lld\n",ans);
      }
  }
}
