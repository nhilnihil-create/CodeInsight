#include<bits/stdc++.h>
using namespace std;

int main()
{
int x1,y1,x2,y2;scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
int dist1,dist2,x3,y3,x4,y4;
dist1=abs(x2-x1),dist2=abs(y1-y2);
if(y1>=y2&&x1>=x2)x3=x2+dist2,y3=y2-dist1,x4=x1+dist2,y4=y1-dist1;
else if(y1>=y2&&x2>=x1)x3=x2+dist2,y3=y2+dist1,x4=x1+dist2,y4=y1+dist1;
else if(y2>=y1&&x1>=x2)x3=x2-dist2,y3=y2-dist1,x4=x1-dist2,y4=y1-dist1;
else x3=x2-dist2,y3=y2+dist1,x4=x1-dist2,y4=y1+dist1;
printf("%d %d %d %d",x3,y3,x4,y4);
}