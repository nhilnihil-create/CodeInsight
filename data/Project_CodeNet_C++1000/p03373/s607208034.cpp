#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y;
int main()
{
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    int ans=1e9;
    for(int i=0;i<=max(x,y);i++)
    {
        ans=min(ans,2*i*c+max(0,x-i)*a+max(0,y-i)*b);
    }
    printf("%d\n",ans);
}
