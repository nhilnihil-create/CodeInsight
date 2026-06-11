#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N],b[N];
int main()
{
    scanf("%d",&n);
    bool flag=false;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]),flag|=a[i]!=b[i];
    if(!flag){printf("0\n");return 0;}
    ll sum=0;
    int mn=inf;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>b[i])
            mn=min(mn,b[i]);
        sum+=a[i];
    }
    printf("%lld\n",sum-mn);
}
