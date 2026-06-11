#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int N;
  cin>>N;
  
  bool can=false;
  
  rep(i,25)rep(j,15)
    if(4*i+7*j==N)can=true;
  
  if(can)cout<<"Yes"<<endl;
  else   cout<<"No"<<endl;
  return 0;
}