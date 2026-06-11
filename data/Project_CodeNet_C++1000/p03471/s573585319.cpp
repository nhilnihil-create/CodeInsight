#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,y,mkr;
  mkr=1;
  cin >> n >> y;
  for(int i=0;i<floor(y/10000)+1;i++){
    for(int j=0;j<floor((y-10000*i)/5000)+1;j++){
      if((y-10000*i-5000*j)%1000 == 0 && i+j+(y-10000*i-5000*j)/1000==n){
        cout << i << ' ' << j << ' ' << (y-10000*i-5000*j)/1000 << endl;
        mkr=0;
        break;
      }
    }
    if(mkr==0){
      break;
    }
  }
  if(mkr==1){
    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
  }
}