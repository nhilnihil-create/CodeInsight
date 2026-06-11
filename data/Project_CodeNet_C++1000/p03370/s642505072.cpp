#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n,x;
  cin>>n>>x;
  vector<int>m(n);
  rep(i,n) cin>>m[i];
  
  sort(m.begin(),m.end());
  
  int cnt=0;
  rep(i,n){
    if(x-m[i]>=0){
    x-=m[i];
    cnt++;
  }else break;
  }
  while(x-m[0]>=0){
    cnt++;
    x-=m[0];
  }
  
  cout<<cnt<<endl;
  return 0;
}