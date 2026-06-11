#include <bits/stdc++.h>
using namespace std;
#define MAXNUM 222111
char s[MAXNUM],t[MAXNUM];
int main()
{
    int h,w,n;scanf("%d%d%d",&h,&w,&n);
    int up=0,down=h+1,lef=0,rig=w+1, x,y;
    scanf("%d%d",&x,&y);
    scanf("%s%s",s+1,t+1);int flag=1;
    for(int i=n;i;i--)
    {
        if(t[i]=='U')down=min(h+1,down+1);
        else if(t[i]=='D')up=max(0,up-1);
        else if(t[i]=='L')rig=min(w+1,rig+1);
        else lef=max(0,lef-1);
        if(s[i]=='U')up++;
        else if(s[i]=='D')down--;
        else if(s[i]=='L')lef++;
        else rig--;
        if(up>=down-1||lef>=rig-1){flag=0;break;}
    }
    if(flag&&(y<rig&&y>lef)&&(x>up&&x<down))printf("YES\n");
    else printf("NO\n");
}