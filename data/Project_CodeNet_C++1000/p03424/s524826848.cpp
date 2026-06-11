#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,i;
  cin >>N ;
  char x;
  bool p,y,w,g;
  p=0;
  y=0;
  w=0;
  g=0;
  for(i=0;i<N;i++){
    cin >>x ;
    if(x=='P' && p==0){
      p=1;
    }
    if(x=='Y' && y==0){
      y=1;
    }
    if(x=='W' && w==0){
      w=1;
    }
    if(x=='G' && g==0){
      g=1;
    }
  }
  if(p==1 && w==1 && g==1){
    if(y==1){
      cout << "Four" <<endl;
    }else{
      cout << "Three" <<endl;
    }
  }
}
