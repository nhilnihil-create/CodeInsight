#include <bits/stdc++.h>
using namespace std;
int x[1005],y[1005],dis[45],cnt,n;
char ans[1005][45];
void calc(int num)
{
    dis[++cnt]=num;
    for(int i=0;i<n;i++)
    {
        if(abs(x[i])>abs(y[i]))
        {
            if(x[i]>0) ans[i][cnt]='R',x[i]-=num;
            else ans[i][cnt]='L',x[i]+=num;
        }
        else 
        {
            if(y[i]>0) ans[i][cnt]='U',y[i]-=num;
            else ans[i][cnt]='D',y[i]+=num;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=30;i>=0;i--)
        calc(1<<i);
    if(x[0]||y[0]) calc(1);
    for(int i=0;i<n;i++)
        if(x[i]||y[i]) 
        {
            printf("-1\n");
            return 0;
        }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
        printf("%d%c",dis[i],i==cnt?'\n':' ');
    for(int i=0;i<n;i++)
        printf("%s\n",ans[i]+1);
    return 0;
}