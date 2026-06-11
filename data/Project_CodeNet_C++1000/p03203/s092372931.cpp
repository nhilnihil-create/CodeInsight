#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;


int y[maxn];
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    memset(y, 127, sizeof(y));
    for(int i=0;i<k;i++)
    {
        int tx, ty;
        scanf("%d%d",&tx,&ty);
        y[tx]=min(y[tx], ty);
    }
    int ans=n;
    int now=1;
    for(int i=2;i<=n;i++)
    {
        if(y[i]<=now){
            ans=i-1;break;
        }
        else if(y[i]==now+1){
            continue;
        }
        else{
            now++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
