#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
int vis[N],a[N];
void creat()
{
    for(int i=2; i<=400; i++)
    {
        if(!vis[i])
        {
            for(int j=i*2; j<=N; j+=i)
                vis[j]=1;
        }
    }
}
int main()
{
 
    memset(vis,0,sizeof(vis));
    creat();
    vis[1]=1;
    int sum=0,n;
    for(int i=1; i<=N; i++)
    {
        if(i%2==1)
        {
            if(vis[i]==0&&vis[(i+1)/2]==0)
                sum++;
        }
 
        a[i]=sum;
    }
    while(scanf("%d",&n)==1)
    {
        while(n--)
        {
            int c,b;
            scanf("%d%d",&c,&b);
 
            printf("%d\n",a[b]-a[c-1]);
        }
    }
}