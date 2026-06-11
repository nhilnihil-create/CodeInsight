#include<bits/stdc++.h>
using namespace std;
const int maxn=300005;
int f[maxn],n,m,cnt;
int getf(int x) {
    if(f[x]==x)return x;
    return f[x]=getf(f[x]);
}
int main() {
    int x,y,z;
    scanf("%d%d",&n,&m);
    for(register int i=1; i<=3*n; i++) {
        f[i]=i;
    }
    for(register int i=1; i<=m; i++) {
        scanf("%d%d%d",&x,&y,&z);
        int fx=getf(x),fy=getf(y);
        f[fy]=fx;
        if(z%2==0) {
            if(getf(x+2*n)==getf(y+n)||getf(x+n)==getf(y+2*n)) {
                puts("0");
                return 0;
            }
            fx=getf(x+n),fy=getf(y+n);
            f[fy]=fx;
            fx=getf(x+2*n),fy=getf(y+2*n);
            f[fy]=fx;
        } else {
            if(getf(x+n)==getf(y+n)) {
                puts("0");
                return 0;
            }
            fx=getf(x+2*n),fy=getf(y+n);
            f[fy]=fx;
            fx=getf(x+n),fy=getf(y+2*n);
            f[fy]=fx;
        }
    }
    for(register int i=1; i<=n; i++) {
        if(f[i]==i) {
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}