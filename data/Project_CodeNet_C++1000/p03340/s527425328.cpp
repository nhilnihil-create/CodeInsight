#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
typedef long long ll;
int a[N],n;
ll ans;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    int sum=0,l=1,t=0;
    for (int i=1;i<=n;i++)
    {
        sum+=a[i];
        t^=a[i];
        while(sum!=t)
        {
            sum-=a[l];
            t^=a[l];
            l++;
        }
        ans+=i-l+1;
    }
    printf("%lld\n",ans);
    return 0;
}
