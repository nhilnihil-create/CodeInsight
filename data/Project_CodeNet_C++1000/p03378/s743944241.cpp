#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  int M;
  int X;
  cin>>N>>M>>X;
  vector<int>A(M);
  int costA=0;
  int costB=0;
  for(int i=0;i<=M-1;i++){
  
    cin>>A[i];
  }
  for(int i=0;i<=M-1;i++){
    
    if(A[i]==X){
    
      costA=i+1;
      costB=M-i;
      break;
    }
    if(A[i]>X){
    
      costA=i;
      costB=M-i;
      break;
    }
  }
  //cout<<costA<<endl<<costB<<endl;
  costA<=costB?cout<<costA:cout<<costB;
  return 0;
}