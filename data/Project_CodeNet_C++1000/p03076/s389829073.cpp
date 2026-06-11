#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B,C,D,E;
  cin>>A>>B>>C>>D>>E;
  
  int A_=A;
  int B_=B;
  int C_=C;
  int D_=D;
  int E_=E;
  
  while(true){
    if(A_%10==0){
      break;
    }
    A_++;
  }
  while(true){
    if(B_%10==0){
      break;
    }
    B_++;
  }
  while(true){
    if(C_%10==0){
      break;
    }
    C_++;
  }
  while(true){
    if(D_%10==0){
      break;
    }
    D_++;
  }
  while(true){
    if(E_%10==0){
      break;
    }
    E_++;
  }
  
  int x=max(A_-A,B_-B);
  int y=max(C_-C,D_-D);
  int z=max(x,y);
  int w=max(z,E_-E);
  
  cout<<A_+B_+C_+D_+E_-w<<endl;
}