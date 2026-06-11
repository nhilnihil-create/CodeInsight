#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >>n>>m;
  if(n==1){
    cout<<m<<endl;
    return 0;
  }
  int kotae=1;
  for(int i=m/n+1;i>=2;--i){
    int tmp=kotae;
    if(m%i==0)kotae=max(kotae,i);
    if(m/kotae<n){
      kotae=tmp;
      break;
    }
  }
  cout<<kotae<<endl;
  return 0;
}