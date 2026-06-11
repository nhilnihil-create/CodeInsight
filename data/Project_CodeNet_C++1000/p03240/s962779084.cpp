#include <bits/stdc++.h>
using namespace std;

main(){
  int n;cin >> n;
  vector<int> x(n),y(n),h(n);
  for(int i=0;i<n;i++) cin >> x[i] >> y[i] >> h[i];
  int max=100;
  for(int posY=0;posY<=max;posY++){
    for(int posX=0;posX<=max;posX++){
      int needH=-1;
      for(int i=0;i<n;i++){
        if(h[i]>0){
          int tmp=h[i]+abs(x[i]-posX)+abs(y[i]-posY);
          if(needH==-1){
            needH=tmp;
          }
          else {
            if(needH!=tmp){
              needH=-2;
              break;
            }
          }
        }
      }
      if(needH==-2) continue;
      for(int i=0;i<n;i++){
        if(h[i]==0){
          int dist=abs(x[i]-posX)+abs(y[i]-posY);
          if(needH>dist){
            needH=-2;
            break;
          }
        }
      }
      if(needH==-2) continue;
      cout << posX <<" "<< posY <<" "<< needH << endl;
      return 0;  
    }
  }
}