#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,x,y,h[2],sl;scanf("%d",&n);bool ok;
  int j[n][3];
  for(i=0;i<n;i++) scanf("%d%d%d",&j[i][0],&j[i][1],&j[i][2]);
  for(x=0;x<=100;x++){
    for(y=0;y<=100;y++){
      ok = true;h[0] = 1;h[1] = 2000000000;
      for(i=0;i<n;i++){
        if(j[i][2]>0){
          sl = j[i][2]+abs(j[i][0]-x)+abs(j[i][1]-y);
          if(sl<h[0] || h[1]<sl){
            ok = false;break;
          } else h[0] = h[1] = sl;
        } else {
          sl = abs(j[i][0]-x)+abs(j[i][1]-y);
          if(sl<h[0]){
            ok = false;break;
          } else h[1] = min(h[1],sl);
        }
      }
      if(ok){
        printf("%d %d %d\n",x,y,h[0]);return 0;
      }
    }
  }
}      