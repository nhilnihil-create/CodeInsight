#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  bool ad=false;
  for(int i=0;i<100;i+=4){
    for(int j=0;j<100;j+=7){
      if(i+j==n){
        ad=true;
      }
    }
  }
  if(ad) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
  
