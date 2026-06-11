#include<iostream>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int e=100*n+ 1800*m;
  int ans=1;
  for(int i=1;i<=m;i++)	ans*=2;
  ans=ans*e;
  cout<<ans<<endl;
  return 0;
}