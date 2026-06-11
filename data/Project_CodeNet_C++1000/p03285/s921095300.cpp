#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  bool TorF=false;
  cin>>n;
  for(int cakes=0;cakes<=100;cakes++){
    for(int donuts=0;donuts<=100;donuts++){
      int price=4*cakes+7*donuts;
      if(n==price){
        TorF=true;
      }
    }
  }
  if(TorF==true){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}