#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int X[N],Y[N];
  int H[N];
  int tempH;
  for(int i=0;i<N;i++){
    cin>>X[i]>>Y[i]>>H[i];
  }
  int ix=0;
  for(int i=0;i<N;i++){
    if(H[i] != 0){
      ix=i;
      break;
    }
  }
  //cout<<ix<<endl;
      

    for(int i=0;i<=100;i++){
      for(int j=0;j<=100;j++){
        tempH=abs(i-X[ix])+abs(j-Y[ix])+H[ix];
        
        int flag=1;
        for(int k=0;k<N;k++){
          if(H[k] != max(tempH-abs(i-X[k])-abs(j-Y[k]),0)){
            //cout<<i<<" "<<j<<" "<<tempH<<" "<<max(tempH-abs(i-X[k])-abs(j-Y[k]),0)<<endl;
            flag=0;
            break;
          }
        }
        if(flag){
          cout<<i<<" "<<j<<" "<<tempH;
          return 0;
        }
      }
    }
  return 0;
}
