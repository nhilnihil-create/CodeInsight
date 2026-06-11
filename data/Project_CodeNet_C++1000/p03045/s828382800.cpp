#include<bits/stdc++.h>
#include<string.h>
#include<vector>
using namespace std;
#define MAX 100005
#define MOD 998244353
#define EPS 0.00000000001
#define INF 1000000000
int P[MAX];
int Find(int x)
{
    if(P[x]==x) return x;
    else
    {
        P[x]=Find(P[x]);
        return P[x];
    }
}
bool Join(int x,int y)
{
    int PoX=Find(x),PoY=Find(y);
    if(PoX==PoY) return false;
    else if(PoX<PoY) P[PoY]=PoX;
    else P[PoX]=PoY;
    return true;
}
int main()
{
    int n,m,i,j,x,y,z;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) P[i]=i;
    int components=n;
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        if(Join(x,y)) components--;
    }
    printf("%d",components);
    return 0;
}
