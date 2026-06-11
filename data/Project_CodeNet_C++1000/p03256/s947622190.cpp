#include <cstdio>
using namespace std;

const int maxn=4e5+5;
int n, m;
char s[maxn];
struct Edge{
    int to, nxt;
}e[maxn*2];
int cnte, fir[maxn], in[maxn];
void addedge(int x, int y){
    Edge &ed=e[++cnte]; in[y]++;
    ed.to=y; ed.nxt=fir[x]; fir[x]=cnte; }
int q[maxn], hd, tl;

int main(){
    scanf("%d%d%s", &n, &m, s+1); int x, y;
    for (int i=1; i<=m; ++i){
        scanf("%d%d", &x, &y);
        if (s[x]==s[y]){  //边为0
            addedge(x*2+1, y*2);
            addedge(y*2+1, x*2); }
        else{
            addedge(x*2, y*2+1);
            addedge(y*2, x*2+1); }
    }
    for (int i=2; i<=n*2+1; ++i)
        if (!in[i]) q[tl++]=i;
    int u, v;
    while (hd<tl){
        u=q[hd++];
        for (int i=fir[u]; i; i=e[i].nxt){
            --in[v=e[i].to]; if (!in[v]) q[tl++]=v; }
    }
    for (int i=2; i<=n*2+1; ++i)
        if (in[i]){ puts("Yes"); return 0; }
    puts("No");
    return 0;
}
