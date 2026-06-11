#include <bits/stdc++.h>
using namespace std;

int main(){
int N;
  cin >> N;
  vector<int> x(N),y(N),h(N);
  for(int i=0;i<N;i++){
    cin >> x[i] >> y[i] >> h[i];
  }
int max=100;
  for(int posy=0;posy<=max;posy++){
    for(int posx=0;posx<=max;posx++){
    int needh=-1;
      for(int i=0;i<N;i++){
        if(h[i]>0){
          int tmp=h[i]+abs(posy-y[i])+abs(posx-x[i]);
          if(needh==-1){
           needh=tmp;
          }
          else{
            if(needh!=tmp){
            needh=-2;
            break;
            }
          }
        }
      }
     if(needh==-2) continue;
     for(int i=0;i<N;i++){
       if(h[i]==0){
       int dist = abs(posy-y[i])+abs(posx-x[i]);
         if(needh>dist){
           needh=-2;
           break;
         }
       }
     } 
     if(needh==-2)continue;
     cout << posx << " " << posy << " " << needh << endl;
    }
  }


}
