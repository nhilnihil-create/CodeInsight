#include<bits/stdc++.h>
#define int  long long
using namespace std;

int n,a[200001],ans;

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    int sum=a[1],sumx=a[1],l=1,r=1;
    for(int i=1;i<=n;i++)
    {
        while(sum==sumx&&r<=n)
            sum+=a[r+1],sumx^=a[r+1],r++;
        ans+=(r-1)-l+1;
        sum-=a[l],sumx^=a[l];
        l++;
        if(r<l)r=l;
    }
    printf("%lld\n",ans);
    return 0;
}
