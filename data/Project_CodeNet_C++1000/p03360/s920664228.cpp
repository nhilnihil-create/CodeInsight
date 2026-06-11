#include <bits/stdc++.h>
using namespace std;

int main()
{
       long long a,b,c,k,x,y,z;
       cin>>a>>b>>c>>k;
       x=max(max(a,b),c);
       y=min(min(a,b),c);
       z=(a+b+c)-(x+y);
       for(int i=0;i<k;i++)
        x*=2;
       cout<<x+y+z;
    return 0;
   }