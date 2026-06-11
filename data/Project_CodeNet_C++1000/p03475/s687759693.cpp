#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 507;
int c[maxn],s[maxn],f[maxn];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d%d",&c[i],&s[i],&f[i]);
    }
    int t=0;
    for(int i=1;i<=n;i++)
    {
        t=0;
        for(int j=i;j<=n-1;j++)
        {
            if(t<s[j])t=s[j];
            else if(t%f[j]==0);
            else t=t-t%f[j]+f[j];
            t+=c[j];
        }
        cout<<t<<endl;
    }
    return 0;
}