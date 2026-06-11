#include <bits/stdc++.h>
using namespace std;

int main(){
  //宣言と入力
  int H,W,N,SX,SY;
  string S,T;
  cin>>H>>W>>N;
  cin>>SX>>SY;
  cin>>S>>T;
  
  int OX=SX;
  int OY=SY;
  
  //U
  for(int i=0;i<N;i++){
    if(S.at(i)=='U'){
      SX--;
    }
    if(SX<1){
      cout<<"NO"<<endl;
      return 0;
    }
    if(T.at(i)=='D' && SX<H){
      SX++;
    } 
  }
  
  SX=OX;
  
  //D
  for(int i=0;i<N;i++){
    if(S.at(i)=='D'){
      SX++;
    }
    if(SX>H){
      cout<<"NO"<<endl;
      return 0;
    }
    if(T.at(i)=='U' && SX>1){
      SX--;
    } 
  }  
  
  //L
  for(int i=0;i<N;i++){
    if(S.at(i)=='L'){
      SY--;
    }
    if(SY<1){
      cout<<"NO"<<endl;
      return 0;
    }
    if(T.at(i)=='R' && SY<H){
      SY++;
    } 
  }  
  
  SY=OY;

  //R
  for(int i=0;i<N;i++){
    if(S.at(i)=='R'){
      SY++;
    }
    if(SY>W){
      cout<<"NO"<<endl;
      return 0;
    }
    if(T.at(i)=='L' && SY>1){
      SY--;
    } 
  } 
  
  cout<<"YES"<<endl;
  return 0;
}

