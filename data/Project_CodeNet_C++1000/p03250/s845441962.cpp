#include<bits/stdc++.h>
#define ft(i,l,r) for(register int i=l;i<=r;i++)
#define fd(i,r,l) for(register int i=r;i>=l;i--)
using namespace std;
int mx=-233,a[5];
int main()
{
    cin>>a[1]>>a[2]>>a[3];
    for(int i=1;i<=3;i++)
      for(int j=1;j<=3;j++)
        for(int k=1;k<=3;k++)
          if(i!=j&&i!=k&&j!=k)
            mx=max(mx,a[i]+a[j]*10+a[k]);
    cout<<mx;
    return 0;
}