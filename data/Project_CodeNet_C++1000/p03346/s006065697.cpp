#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);a[x]=i;
    }
    int ans=0,t=1;
    for(int i=2;i<=n;i++)
        if(a[i]>a[i-1]) t++;
    else
        ans=max(ans,t),t=1;
    ans=max(ans,t);
    printf("%d\n",n-ans);
}
