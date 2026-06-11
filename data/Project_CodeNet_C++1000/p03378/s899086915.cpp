#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M,X;
  cin>>N>>M>>X;
  int a[M];
  for(int i=0;i<M;i++){
    cin>>a[i];
  }
  int g0=0,gN=0;
  
  for(int i=0;i<M;i++){
    if(a[i]<X){
      g0++;
    }
    else if(a[i]>X){
      gN++;
    }
  }
  cout<<min(g0,gN)<<endl;
}