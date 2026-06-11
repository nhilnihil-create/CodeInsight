#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N=1000005;
int n,m;
int fa[N],dis[N];
int finds(int x) {
  if(x==fa[x]) return x;
  int ret=fa[x];
  fa[x]=finds(fa[x]);
  dis[x]+=dis[ret];
  return fa[x];
}
int main() {
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i) fa[i]=i;
  for (int i=1;i<=m;++i) {
    int x,y,d;
    scanf("%d%d%d",&x,&y,&d);
    int fx=finds(x),fy=finds(y);
    if(fx==fy && (dis[x]-dis[y])!=d) {
      puts("No");
      return 0;
    }
    if(fx!=fy) {
      fa[fx]=fy;
      dis[fx]=-dis[x]+dis[y]+d;
    }
  }
  puts("Yes");
  return 0;
}
