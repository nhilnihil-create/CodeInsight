#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x,m;
  cin>>n>>x>>m;
  int l=m;
  x-=m;
  for(int i=1;i<n;i++){
    cin>>m;
    x-=m;
    l=min(l,m);
  }
  cout<<n+x/l<<endl;
}