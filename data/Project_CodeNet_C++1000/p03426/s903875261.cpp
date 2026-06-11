#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct stu
{
    int x,y;
};
stu vp[90005];
int k[90005];
int main()
{
    int h,w,d,num;
    scanf("%d %d %d",&h,&w,&d);
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            scanf("%d",&num);
            vp[num].x=i;
            vp[num].y=j;
        }
    }
    for(int i=d+1;i<=h*w;i++)
    {
        k[i]=k[i-d]+abs(vp[i].x-vp[i-d].x)+abs(vp[i].y-vp[i-d].y);
    }
     int q;
     scanf("%d",&q);
     for(int i=0;i<q;i++)
     {
         int x,y;
         scanf("%d %d",&x,&y);
         printf("%d",abs(k[y]-k[x]));

         if(i!=q-1)
            printf("\n");
     }

}
