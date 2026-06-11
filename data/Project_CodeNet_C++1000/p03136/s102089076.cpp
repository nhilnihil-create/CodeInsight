#include<iostream>
using namespace std;
int main(){
  int n;cin>>n;
  int mx=0;
  int sm=0;
  for(int i=0;i<n;++i){
    int buf;cin>>buf;
    sm+=buf;
    mx=max(mx,buf);
  }
  if(mx<sm-mx){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}
