#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include<cstring>
using namespace std;
const int maxn=100001;
int f[maxn];
int d[maxn];
int find(int x)
{
    if(f[x]==x)
        return x;
    int r=find(f[x]);
    d[x]=d[f[x]]+d[x];
    return f[x]=r;
}


int fix(int x,int y,int z)
{
    int fx=find(x);
    int fy=find(y);
    if(fx==fy)
     return z==d[y]-d[x];
    f[fy]=fx;
    d[fy]=d[x]+z-d[y];
    return 1;
}

int main()
{
    int n,m;
    int flag=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(flag)
            flag=fix(x,y,z);
    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
