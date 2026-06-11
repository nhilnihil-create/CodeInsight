#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int n,a,b,s[N],f1[N],f2[N];
int t1[N],t2[N];
int query1(int x)
{
    int ans=0;
    while(x)
        ans=max(ans,t1[x]),x-=x&-x;
    return ans;
}
int query2(int x)
{
    int ans=0;
    x=n-x+1;
    while(x)
        ans=max(ans,t2[x]),x-=x&-x;
    return ans;
}
void add1(int x,int v)
{
    while(x<=n)
        t1[x]=max(t1[x],v),x+=x&-x;
}
void add2(int x,int v)
{
    x=n-x+1;
    while(x<=n)
        t2[x]=max(t2[x],v),x+=x&-x;
}
bool check()
{
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
    {
        f1[s[i]]=max(query1(s[i])+1,1);
        f2[s[i]]=max(query2(s[i])+1,1);
        add1(s[i],f1[s[i]]);
        add2(s[i],f2[s[i]]);
        ans1=max(ans1,f1[s[i]]);
        ans2=max(ans2,f2[s[i]]);
    }
    return ans1==a&&ans2==b;
}
void solve(int a,int b)
{
    int tot=0;
    for(int i=n-a+1;i<=n;i++)
        s[++tot]=i;
    n-=a;
    b--;
    if(b==0)
    {
        if(n==0)
            for(int i=1;i<=tot;i++) cout<<s[i]<<' ';
        else cout<<-1;
        return;
    }
    int len=n/b,k=n%b;
    for(int i=1;i<=k;i++)
    {
        int x=len+1;
        for(int i=n-x+1;i<=n;i++)
            s[++tot]=i;
        n-=x;
    }
    for(int i=1;i<=b-k;i++)
    {
        int x=len;
        for(int i=n-x+1;i<=n;i++)
            s[++tot]=i;
        n-=x;
    }
    n=tot;
    if(!check()) printf("-1\n");
    else for(int i=1;i<=n;i++)
        printf(i==n?"%d\n":"%d ",s[i]);
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    if(a+b-1>n||a>n||b>n) printf("-1\n");
    else solve(a,b);
}
