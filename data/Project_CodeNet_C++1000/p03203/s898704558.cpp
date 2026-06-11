#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
struct node
{
    int x;
    int y;
    int ans;
}Node[200000+10];
map<ll,bool>df;
bool cmp1(struct node a,struct node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
ll sum(ll x,ll y)
{
    return x*1000000+y;
}
int my_min(int a,int b)
{
    return a<b? a:b;
}
int main()
{
    int h,w,n;
    scanf("%d %d %d",&h,&w,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&Node[i].x,&Node[i].y);
        df[sum(Node[i].x,Node[i].y)]=true;
    }
    sort(Node,Node+n,cmp1);
    int ans=h;
    int nowx,nowy;
    nowx=nowy=1;
    for(int i=0;i<n;i++)
    {
        int dis=Node[i].x-nowx;
        if(dis>0)
        {
            if(nowy+dis>Node[i].y)
            {
               	printf("%d",Node[i].x-1); 
            	return 0;
            }
			if(nowy+dis==Node[i].y)
                nowy+=(dis-1);
            if(nowy+dis<Node[i].y)
                nowy+=dis;
            nowx=Node[i].x;
        }
    }
    printf("%d",ans);
    return 0;
}

