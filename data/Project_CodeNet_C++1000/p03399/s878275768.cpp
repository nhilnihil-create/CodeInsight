#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a,b,c,d,ans=0;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  if(a>=b)
      ans+=b;
  
  else
     ans+=a;
  
  if(c>=d)
      ans+=d;
  
  else
    ans+=c;
  
  printf("%d",ans);
}