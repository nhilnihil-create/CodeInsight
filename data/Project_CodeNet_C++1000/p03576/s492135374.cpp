#include<bits/stdc++.h>
using namespace std;


int main(){
  long long int a,b,x[55]={0},y[55]={0};
  cin >> a >> b;
  
  for(int i=0;i<a;i++){
    cin >> x[i] >> y[i];
  }
  
  long long int  ans=9e18;
  
  for(int xi=0;xi<a;xi++){
    for(int xj=0;xj<a;xj++){
      for(int yi=0;yi<a;yi++){
        for(int yj=0;yj<a;yj++){
          long long int xa=x[xi],xb=x[xj],ya=y[yi],yb=y[yj];
          
          int res=0;
          for(int i=0;i<a;i++){
            if(min(xa,xb)<=x[i] && x[i]<=max(xa,xb)&& min(ya,yb)<=y[i] && y[i]<=max(ya,yb)){
              res++;
            }
          }
          
          if(res>=b){
            ans= min(ans,abs(xa-xb)*abs(ya-yb));
          }
        }
      }
    }
  }
  cout << ans << endl;
}
