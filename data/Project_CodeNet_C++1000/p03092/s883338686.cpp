#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
ll mem[5005][5005];
int p[5005], pos[5005];
ll dp(int id, int cur){
    if (mem[id][cur] != -1) return mem[id][cur];
    if (id == 0) return mem[id][cur] = 0;
    if (pos[id] > cur) {
        //printf("%d at %d needs to move to %d, cost %d\n",id,pos[id],cur,b);
        return mem[id][cur] = dp(id-1,cur)+b; ///move id to cur.
    }
    //printf("%d at %d, can move to %d, cost %d\n",id,pos[id],cur,a);
    return mem[id][cur] =  min(dp(id-1,pos[id]),dp(id-1,cur)+a);
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for (int i = 1; i <= n; i++){
        scanf("%d",&p[i]);
        pos[p[i]] = i;
    }
    memset(mem,-1,sizeof(mem));
    printf("%lld",dp(n,n));
}
