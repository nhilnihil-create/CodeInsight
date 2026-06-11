#include <bits/stdc++.h>
using namespace std;

int main() {
  
  /////箱の宣言/////
  
  int c[3][3]; //3x3の行列
  bool point=0; //判定用
  
  
  /////入力部/////
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>c[i][j];
    }
  }
  
  for(int i=0;i<2;i++){
    int data_norm=c[i][0]-c[i+1][0];
    int data=0;
    for(int j=0;j<3;j++){
      data=c[i][j]-c[i+1][j];
      if(data_norm!=data)point=1;
    }
  }
  
  for(int i=0;i<2;i++){
    int data_norm=c[0][i]-c[0][i+1];
    int data=0;
    for(int j=0;j<3;j++){
      data=c[j][i]-c[j][i+1];
      if(data_norm!=data)point=1;
    }
  }
  if(point) cout<<"No"<<endl;
  
  else cout<<"Yes"<<endl;
}
  
