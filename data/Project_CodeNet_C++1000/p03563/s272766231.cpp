#include <bits/stdc++.h>
using namespace std;
int main(){
  int r,g;
  cin>>r>>g;
  if(r==g){
    cout<<r<<endl;
    return 0;
  }
  if(r>g){
    cout<<g-(r-g)<<endl;
  }
  else {
    cout<<g+g-r<<endl;
  }
  return 0;
}