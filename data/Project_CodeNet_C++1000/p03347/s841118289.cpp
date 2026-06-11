#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int sum=0;
    ll ans=0;
    for(int i=n;i>=1;i--)
    {
        sum--;
        if(sum>a[i]){printf("-1\n");return 0;}
        if(a[i]!=sum)
        {
            ans+=a[i];
            sum=a[i];
        }
    }
    if(sum!=0){printf("-1\n");return 0;}
    printf("%lld\n",ans);
}
