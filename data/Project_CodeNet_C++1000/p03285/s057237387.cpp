#include<iostream>
using namespace std;
int main(){
  int n;cin>>n;
  bool flag=false;
  for(int i=0;i<=n;++i){
    for(int j=0;j<=n;++j){
      if(i*4+j*7==n)flag=true;
    }
  }
  if(flag){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}