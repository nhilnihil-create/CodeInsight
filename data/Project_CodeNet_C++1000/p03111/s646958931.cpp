#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b,c,i,B = 0,ans = 1000000000,now,g;scanf("%d%d%d%d",&n,&a,&b,&c);
  int l[n],t[4];
  for(i=0;i<n;i++) scanf("%d",&l[i]);
  while(B<(1<<(n*2))){
    t[0] = t[1] = t[2] = t[3] = now = 0;
    for(i=0;i<n;i++){
      g = bool(B&(1<<(i*2)))+bool(B&(1<<(i*2+1)))*2;
      if(g<3 && t[g]) now += 10;
      t[g] += l[i];
    }
    if(t[0] && t[1] && t[2]) ans = min(ans,abs(a-t[0])+abs(b-t[1])+abs(c-t[2])+now);
    B++;
  }
  printf("%d\n",ans);
}