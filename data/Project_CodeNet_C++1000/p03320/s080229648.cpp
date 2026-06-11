#include<bits/stdc++.h>
using namespace std;
long long k,xb,s,x=1;
inline double check(long long xx)
{
    long long ss=0,t=xx;
    while (xx>0)
    {
      ss+=xx%10;
      xx/=10;
    }
    return t*1.0/(ss*1.0);
}
int main()
{
    scanf("%lld",&k);
    while (xb<k)
      if ((s/x)%10!=9)
	  {
        s+=x;++xb;
        printf("%lld\n",s);
      }else
	  {
        if (check(s+x)>check(s+10*x))
          x*=10;
        s+=x;++xb;
        printf("%lld\n",s);
      }
    return 0;
}