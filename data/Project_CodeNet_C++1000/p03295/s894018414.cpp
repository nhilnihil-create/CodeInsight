#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>
#define LL long long
#define N 100005
#define maxn 10005
#define INFINITY 0x3f3f3f3f
#define mase(a,b) memset(a,b,sizeof(a))
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define DS DisputeSegement
using namespace std;
struct DisputeSegement
{
    int x,y;

}SENode[N];
bool Cmp(DS A,DS B)
{
    if(A.y!=B.y)
    {
        return A.y<B.y;
    }
    else
    {
        return A.x<B.x;
    }
}
int main()
{
    int n,m;
    int miny=INFINITY;
    int re;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&SENode[i].x,&SENode[i].y);
        miny=MIN(miny,SENode[i].y);
    }
    sort(SENode,SENode+m,Cmp);
    re=1;
    for(int i=0;i<m;i++)
    {
        if(SENode[i].x>=miny)
        {
            re++;
            miny=SENode[i].y;
        }

    }
    printf("%d\n",re);
    return 0;
}
