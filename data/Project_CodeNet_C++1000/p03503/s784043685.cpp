#include<iostream>
using namespace std;
#define MAXN 100

int N;
int F[MAXN][5][2];
int P[MAXN][11];

int main(){
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<5;j++){
      cin>>F[i][j][0]>>F[i][j][1];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<=10;j++){
      cin>>P[i][j];
    }
  }
  int joi[5][2];
  int ans=-2000000000;
  for(int bitb=0;bitb<(1<<5);bitb++){
    for(int bita=0;bita<(1<<5);bita++){
      for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
          joi[i][j]=0;
        }
      }
      if(bitb==0&&bita==0) continue;
      for(int i=0;i<5;i++){
        if((bitb>>i)&1) joi[i][0]=1;
        if((bita>>i)&1) joi[i][1]=1;
      }
      int tmp=0;
      for(int k=0;k<N;k++){
        int cnt=0;
        for(int i=0;i<5;i++){
          for(int j=0;j<2;j++){
            if(joi[i][j]==1&&F[k][i][j]==1) cnt++;
          }
        }
        tmp+=P[k][cnt];
      }
      ans=max(ans,tmp);
    }
  }
  cout<<ans<<endl;
  return 0;
}