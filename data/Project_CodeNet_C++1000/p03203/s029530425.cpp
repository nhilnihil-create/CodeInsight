#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Q=1<<18;
struct dt{
    int x,y;
    void R()
    {scanf("%d%d",&x,&y);}
}a[Q];
bool operator<(dt a,dt b)
{return a.y==b.y?a.x<b.x:a.y<b.y;}
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    int ans=n;
    for(int i=1;i<=q;i++)
        a[i].R();
    sort(a+1,a+q+1);
    for(int i=1,mx=0;i<=q;i++){
		int mys=a[i].x+1-a[i].y;
		if(mys<=mx+1)mx=max(mx,mys);
		else ans=min(ans,a[i].x-1);
	}
    printf("%d",ans);
    return 0;
}