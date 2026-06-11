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
#include <functional>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
int L,i,n=20,a[100],b[100],c[100],cnt;
auto ae=[](int u,int v,int w){return a[++cnt]=u,b[cnt]=v,c[cnt]=w;};
int solve (int L,int i){
    if(L==0) return i<n&&ae(i,n,0);
    if(L==1) return ae(i,n,0),ae(i,n,1);
    if(L&1) return ae(i,i+1,0),ae(i,i+1,L+1>>1),solve(L>>1,i+1);
    else return ae(i,i+1,0),ae(i,i+1,L>>1),ae(i,n,L),solve(L-1>>1,i+1);
}
int main(){
    scanf("%d",&L);
    solve(L-1,1);
    printf("%d %d\n",n,cnt);
    rep(i,1,cnt) printf("%d %d %d\n",a[i],b[i],c[i]);
    return 0;
}