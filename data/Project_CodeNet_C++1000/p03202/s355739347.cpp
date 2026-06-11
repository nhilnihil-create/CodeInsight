#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,aaa[maxn],pos[maxn],num[maxn];
int top,ans;
bool check(int ans)
{
    top=0;
    for(int i=2;i<=n;i++)
    if(aaa[i]<=aaa[i-1])
    {
        int x=aaa[i];
        while(top&&pos[top]>x) top--;
        while(top&&pos[top]==x&&num[top]==ans) top--,x--;
        if(x==0) return 0;
        else if(pos[top]<x)
        {
            pos[++top]=x;
            num[top]=2;
            if(ans==1)
                return 0;
        }
        else num[top]++;
    }
    return 1;
}
int main(int argc, char** argv)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&aaa[i]);
    int l=1,r=n,ans;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
            r=mid-1,ans=mid;
        else
            l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
