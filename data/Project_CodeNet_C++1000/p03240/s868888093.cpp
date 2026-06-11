#define George_Plover
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 111
#define LL long long
#define INF (-1)
using namespace std;
int n;
struct POINT{
    int x,y;
    LL h;
}p[MAXN];
bool cmp(POINT x,POINT y)
{
    return x.h>y.h;
}
int dis(POINT x,POINT y)
{
    return abs(x.x-y.x)+abs(x.y-y.y);
}
LL check(POINT & aim)
{
    LL std=p[1].h+dis(aim,p[1]);
    for(int i=2;i<=n;i++)
    {
        
        if(p[i].h+dis(p[i],aim)!=std &&!(p[i].h==0 && p[i].h+dis(p[i],aim)>std))
            return 0;
    }
    return std;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%lld",&p[i].x,&p[i].y,&p[i].h);
    }
    sort(p+1,p+n+1,cmp);
    POINT aim;
    
    for(aim.x=0;aim.x<=100;aim.x++)
        for(aim.y=0;aim.y<=100;aim.y++)
        {
            if(check(aim))
            {
                printf("%d %d %lld\n",aim.x,aim.y,check(aim));
                return 0;
            }
        }
    
    
    return 0;
}
