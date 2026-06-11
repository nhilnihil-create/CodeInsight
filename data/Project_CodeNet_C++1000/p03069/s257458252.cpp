#include<bits/stdc++.h>
using namespace std;
int n,l[200005],r[200005];
char s[200005];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        l[i]=l[i-1];
        if(s[i]=='#') l[i]++;
    }
    for(int i=n;i>=1;i--)
    {
        r[i]=r[i+1];
        if(s[i]=='.') r[i]++;
    }
    int ans=1e9;
    for(int i=1;i<n;i++)
        ans=min(ans,l[i]+r[i+1]);
    ans=min(ans,l[n]);
    ans=min(ans,r[1]);
    printf("%d\n",ans);
}

