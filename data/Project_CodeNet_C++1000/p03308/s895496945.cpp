#include<iostream>
using namespace std;
int main(){
  int n,ma=0,mi=1000000001;
  cin>>n;
  for(int i=0;i<n;++i){
    int a;
    cin>>a;
    if(a<mi)
      mi=a;
    if(a>ma)
      ma=a;
  }
  if(ma==mi)
    cout<<0<<endl;
  else
    cout<<abs(ma-mi)<<endl;
}