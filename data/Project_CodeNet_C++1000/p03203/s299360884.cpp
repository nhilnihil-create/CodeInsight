#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;


struct SHIT
{
    int x, y;
}shit[maxn];
bool cmp(SHIT a, SHIT b)
{
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d%d",&shit[i].x,&shit[i].y);
    }
    sort(shit,shit+k, cmp);
    int shit_cnt=0;
    int ans=n;
    int now=1;
    for(int i=2;i<=n;i++)
    {
        //printf("%d %ds\n",i, now);
        while(shit[shit_cnt].x < i && shit_cnt<k){
            shit_cnt++;
        }
        if(shit_cnt==k) break;
        if(shit[shit_cnt].x!=i){
            now++;
            continue;
        }
        if(shit[shit_cnt].y<=now){
            //printf("%d %d %d\n", shit[shit_cnt].x, shit[shit_cnt].y, now);
            ans=i-1;break;
        }
        else if(shit[shit_cnt].y==now+1){
            continue;
        }
        else{
            //printf("%d is ++ %d %d\n",i,shit[shit_cnt].x, shit[shit_cnt].y);
            now++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
