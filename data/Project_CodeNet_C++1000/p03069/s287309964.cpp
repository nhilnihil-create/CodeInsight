#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  string S;
  cin>>S;
  int leftb=0;
  int rightw=0;
  int minc=200000;
  int cntw=0;
  int cntb=0;
  int W[N+1];
  int B[N+1];
  W[0]=0;
  B[0]=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='#'){
      cntb++;
    }
    B[i+1]=cntb;
  }
  for(int i=0;i<N;i++){
    if(S.at(N-i-1)=='.'){
      cntw++;
    }
    W[N-i-1]=cntw;
  }
  for(int i=0;i<N+1;i++){
    //cout<<i<<" "<<W[i]<<" "<<B[i]<<endl;
    minc=min(minc,W[i]+B[i]);
  }
  
  cout<<minc<<endl;
  
  
  return 0;
}

  