#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin>>H>>W;
  int C[10][10];
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      cin>>C[i][j];
    }
  }

  for(int j=0;j<10;j++){
    for(int k=0;k<10;k++){
      for(int i=0;i<10;i++){
        if(C[i][j]>C[i][k]+C[k][j]) C[i][j]=C[i][k]+C[k][j];
      }
    }
  }   
  for(int j=0;j<10;j++){
    for(int k=0;k<10;k++){
      for(int i=0;i<10;i++){
        if(C[i][j]>C[i][k]+C[k][j]) C[i][j]=C[i][k]+C[k][j];
      }
    }
  }   
  for(int j=0;j<10;j++){
    for(int k=0;k<10;k++){
      for(int i=0;i<10;i++){
        if(C[i][j]>C[i][k]+C[k][j]) C[i][j]=C[i][k]+C[k][j];
      }
    }
  }   
  int temp;
  int ans=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>temp;
      if(temp != -1) ans+=C[temp][1];
    }
  }
  cout<<ans<<endl;
  return 0;
}

