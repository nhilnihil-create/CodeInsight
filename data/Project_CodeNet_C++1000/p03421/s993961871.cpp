#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t;
const int maxn=1e6+5;
int n,m,f=0;
int res[maxn];
int main()
{
    int a,b,n,m;
    scanf("%d%d%d",&m,&a,&b);
    n=m;
    ll k=(ll)a*b;
    if(a+b-1>n || k<n)
    {
        printf("-1\n");
        return 0;
    }

    for(int i=m-a+1;i<=m;i++)
    {
        res[++f]=i;
        n--;
    }
    b--;
    int s=n;
    for(int i=b;i>0;i--)
    {
        int ans=min(a,n-i+1);
        for(int j=n-ans+1;j<=n;j++)
            res[++f]=j;
        n-=ans;
    }
    for(int i=1;i<=m;i++)
        printf(i==1?"%d":" %d",res[i]);
    return 0;
}