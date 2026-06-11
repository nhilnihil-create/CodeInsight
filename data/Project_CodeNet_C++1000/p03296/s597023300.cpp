#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int t=1,ans=0;
    for(int i=2;i<=n;i++)
        if(a[i]==a[i-1]) t++;
    else ans+=t/2,t=1;
    ans+=t/2;
    printf("%d\n",ans);
}
