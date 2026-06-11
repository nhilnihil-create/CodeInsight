#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
const int maxn=1010;
int n,x[maxn],y[maxn],f[2],a[100],m;
int main(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&x[i],&y[i]),f[(x[i]+y[i])&1]++;
    if(f[0]&&f[1]) return puts("-1"),0;
    if(f[0]) m=1,a[1]=1;
    rep(i,0,30) a[++m]=1<<i;
    printf("%d\n",m);
    per(i,m,1) printf("%d ",a[i]);puts("");
    rep(i,1,n){
        if(f[0]) ++x[i];
        per(j,30,0)
            if(abs(x[i])>abs(y[i]))
                putchar(x[i]>0?'R':'L'),x[i]>0?(x[i]-=1<<j):(x[i]+=1<<j);
            else 
                putchar(y[i]>0?'U':'D'),y[i]>0?(y[i]-=1<<j):(y[i]+=1<<j);
        if(f[0]) putchar('L');
        puts("");
    }
    return 0;
}