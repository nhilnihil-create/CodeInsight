#include<iostream>
#include<vector>
using namespace std;
int main(){

  int D,N;
  cin>>D>>N;
  int ans=0;
  switch(D){
  
    case 0:
      if(N==100){
      
        ans=101;
      }
      else{
      
        ans=N;
      }
      break;
    case 1:
      if(N==100){
      
        ans=10100;
      }
      else{
      
        ans=N*100;
      }
      break;
    case 2:
      if(N==100){
      
        ans=1010000;
      }
      else {
      
        ans=N*10000;
      }
      break;
  }
  cout<<ans;
}