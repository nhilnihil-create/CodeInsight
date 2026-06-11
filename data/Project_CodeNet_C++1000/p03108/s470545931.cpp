#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
const int maxn=1e5+5;
int o[maxn],l[maxn],r[maxn];
long long w[maxn],s[maxn];

int sfind(int f)
{
    return f==o[f]?f:o[f]=sfind(o[f]);
}

long long sunion(int l,int r)
{
    int x,y;
    long long ans=0;
    x=sfind(l);
    y=sfind(r);
    if(x!=y)
    {
        o[x]=y;
        ans=w[x]*w[y];
        //cout<<x<<' '<<y<<'*'<<ans<<endl;
        w[y]+=w[x];
    }
    return ans;
}

int main()
{
    long long n,m,ans;
    while(cin>>n>>m)
    {
        ans=n*(n-1)/2;
        for(int i=1;i<=n;i++)
            o[i]=i,w[i]=1;
        for(int i=0;i<m;i++)
            cin>>l[i]>>r[i];
        for(int i=m-1;i>=0;i--)
        {
            s[i]=ans;
            ans-=sunion(l[i],r[i]);
        }
        for(int i=0;i<m;i++)
            cout<<s[i]<<endl;
    }
    return 0;
}
