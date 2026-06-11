#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod =1e9+7;
typedef long long ll;
int ans[N],k=0;
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(a+b-1>n || n>1ll*a*b)
    {
        puts("-1");
    }
    else
    {
        for(int i=n-a+1;i<=n;i++)
            ans[++k]=i;
        n-=a;
        for(int i=2;i<=b;i++)
        {
            int h=min(a,n-b+i);
            for(int j=n-h+1;j<=n;j++)
                ans[++k]=j;
            n-=h;
        }
    }
    for(int i=1;i<=k;i++)
        printf("%d ",ans[i]);
    return 0;
}
