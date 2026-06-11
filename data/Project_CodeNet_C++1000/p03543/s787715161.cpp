#include <bits/stdc++.h>
using namespace  std;

int main(){
  int N;
  char A[4];
  cin>>N;
  for(int i=0;i<4;i++){
    A[i]=N%10;
    N=N/10;
  }  
  if(A[1]==A[2]&&(A[0]==A[1]||A[2]==A[3])){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}