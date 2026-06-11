#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
struct node
{
    int x,v;
}s[200001];
bool judge(int x)
{
    int cnt=0;
    for(int i=2;i<=n;i++)
        if(a[i]<=a[i-1])
        {
            if(x==1) return false;
            while(cnt&&s[cnt-1].x>a[i])
                cnt--;
            int t=a[i];
            while(t>0&&cnt)
            {
                if(t>s[cnt-1].x) break;
                if(t==s[cnt-1].x)
                {
                    s[cnt-1].v++;
                    if(s[cnt-1].v<x) break;
                    else cnt--;
                }
                t--;
            }
            if(t<=0) return false;
            if(cnt==0||t!=s[cnt-1].x)
                s[cnt].x=t,s[cnt++].v=1;
        }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int l=1,r=n,ans;
    while(l<=r)
    {
        int m=l+r>>1;
        if(judge(m)) ans=m,r=m-1;
        else l=m+1;
    }
    printf("%d\n",ans);
}
