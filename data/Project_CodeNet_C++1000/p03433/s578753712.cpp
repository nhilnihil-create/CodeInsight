#include<iostream>
using namespace std;
int main(){
  int n;cin>>n;
  int a;cin>>a;
  n%=500;
  if(a>=n){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}