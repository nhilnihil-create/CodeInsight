#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
#define LL long long
#define N 500
#define lowb(x) x&-x
 
int c[N][N];
map<pair<int,int>,int>mp;
void add(int x,int y)
{
    for(int i=x;i<=N;i+=lowb(i))
    {
        for(int j=y;j<=N;j+=lowb(j))
        {
            c[i][j]+=1;
        }
    }
}
 
int sum(int x,int y)
{
    int ans=0;
    for(int i=x;i;i-=lowb(i))
    {
        for(int j=y;j;j-=lowb(j))
        {
            ans+=c[i][j];
        }
    }
    return ans;
}
int main()
{
    int n,m,q;
    int l,r;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&l,&r);
        add(l,r);
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",sum(r,r)-sum(r,l-1)-sum(l-1,r)+sum(l-1,l-1));
    }
}