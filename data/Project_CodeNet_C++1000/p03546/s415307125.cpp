#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int H,W;
int c[10][10];
int A[200][200];

int main(){
  scanf("%d%d",&H,&W);
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      scanf("%d",&c[i][j]);
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      scanf("%d",&A[i][j]);
    }
  }
  for(int k=0;k<10;k++){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        if(c[i][j]>c[i][k]+c[k][j]) c[i][j]=c[i][k]+c[k][j];
      }
    }
  }
  int ans=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(A[i][j]!=-1){
        ans+=c[A[i][j]][1];
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}