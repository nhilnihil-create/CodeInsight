#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include<map>
#include<cstring>
#define INF 1e9+10
using namespace std;
typedef struct Pointx{
    int x,y,h;
}point;
int n,H,yes,done=0,res,t;
point coor[105];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&coor[i].x,&coor[i].y,&coor[i].h);
        if(coor[i].h>0)
            t=i;
    }
    for(int cx=0;cx<=100;cx++)
        for(int cy=0;cy<=100;cy++){
            yes=1;
            H=coor[t].h+abs(coor[t].x-cx)+abs(coor[t].y-cy);
            for(int i=1;i<=n;i++){
                res=max(H-abs(coor[i].x-cx)-abs(coor[i].y-cy),0);
                if(coor[i].h!=res){
                    yes=0;
                    break;
                }
            }
            if(yes){
                printf("%d %d %d",cx,cy,H);
                return 0;
            }
        }
}