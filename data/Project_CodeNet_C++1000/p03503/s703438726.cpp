#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int F[N][10];
  for(int i=0;i<N;i++){
    for(int j=0;j<10;j++){
      cin>>F[i][j];
    }
  }
  int P[N][11];
  for(int i=0;i<N;i++){
    for(int j=0;j<11;j++){
      cin>>P[i][j];
    }
  }  
  
  int maxpro=(-1000000000);
  int pro=0;

  
  for(int i=1;i<(1<<10);i++){
    int C[N]={0};
    pro=0;
    for(int j=0;j<10;j++){
      if(i & (1<<j)){
        for(int k=0;k<N;k++){
          if(F[k][j]==1){
            C[k]++;
          }
        }
      }
    }
    for(int l=0;l<N;l++){
      pro+=P[l][C[l]];
    }
    maxpro=max(pro,maxpro);
  } 
  cout<<maxpro<<endl;   

  return 0;
}