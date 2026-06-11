#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;cin>>N;
  vector<int> x(N);
  vector<int> y(N);
  vector<int> h(N);
  for(int i=0;i<N;i++){
    cin>>x[i]>>y[i]>>h[i];
  }
  int CX=0,CY=0,AH=0;
  for(int cx=0;cx<=100;cx++){
    for(int cy=0;cy<=100;cy++){
      int H=0;
      for(int i=0;i<N;i++){
        if(h[i]==0)continue;
        H=abs(x[i]-cx)+abs(y[i]-cy)+h[i];
        if(H>100)break;
        break;
      }
      bool ok=true;
      for(int i=0;i<N;i++){
        if(h[i]!=max(H-abs(x[i]-cx)-abs(y[i]-cy),0)){
          ok=false;
        }
      }
      if(ok){
        AH=H;
        CX=cx;CY=cy;
      }
    }
  }
  cout<<CX<<" "<<CY<<" "<<AH<<endl;
}
