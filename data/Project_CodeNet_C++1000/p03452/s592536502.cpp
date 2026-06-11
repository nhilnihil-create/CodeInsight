#include<cstdio>
using namespace std;
int n, m, pre[100005], dist[100005];
inline int find(int x){
    if(pre[x]^x) {
    	int nf = pre[x]; pre[x] = find(pre[x]); dist[x] += dist[nf];
	}
    return pre[x];
}
int main(){
	bool flag=true;
    scanf("%d%d", &n, &m);
    for(register int i=1; i<=n; ++i)pre[i]=i;
    for(register int i=1; i<=m; ++i){
        int l, r, delta;
        scanf("%d%d%d", &l, &r, &delta);
        int ll = find(l), rr = find(r);
        if(ll==rr&&dist[l]-dist[r]!=delta)flag=false;
        if(ll^rr){
            pre[ll] = rr;
            dist[ll] = delta + dist[r] - dist[l];
        }
    }
    if(flag)printf("Yes\n");
    else printf("No\n");
    return 0;
} 