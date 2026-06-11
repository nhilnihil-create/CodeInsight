#include<iostream>
using namespace std;
int main(){
  int n;cin>>n;
  long long sm=0;
  for(int i=0;i<n;++i){
    int buf;cin>>buf;
    sm+=buf;
  }
  sm-=n;
  cout<<sm<<endl;
  return 0;
}