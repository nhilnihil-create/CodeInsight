#include <bits/stdc++.h>
using namespace std;

#define a 10000
#define b 5000
#define c 1000

void solve(){
  int n,y,num;
  int d[3]={0,0,0};
  scanf("%d %d",&n,&y);
    
    d[0]=(int)(y/a);
    y%=a;
    d[1]=(int)(y/b);
    y%=b;
    d[2]=(int)(y/c);
    y%=c;
    num=d[0]+d[1]+d[2];
    while(num<n){
      if(num+4<=n){
        if(d[1]>0){
          d[1]--;
          d[2]+=5;
        }else if(d[0]>0){
          d[0]--;
          d[1]+=2;
        }else{
          break;
        }
      }else if(d[0]>0){
          d[0]--;
          d[1]+=2;
      }else{
          break;
      }
     num=d[0]+d[1]+d[2];
    }
    if(num==n)printf("%d %d %d\n",d[0],d[1],d[2]);
    else printf("-1 -1 -1\n");
}
int main(){
  /*
  int q;
  scanf("%d",&q);
  while(--q)solve();
  */
  solve();

  return 0;
}