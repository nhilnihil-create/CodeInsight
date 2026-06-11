#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int k=a[n]/2,m=k+1,ans;
    for(int i=1;i<n;i++)
    {
        int t=min(a[i],a[n]-a[i]);
        if(k-t<m)
            m=k-t,ans=a[i];
    }
    printf("%d %d\n",a[n],ans);
}
