#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,D,X[11];
  cin>>r>>D>>X[0];
  for(int i=1;i<11;i++) {
    X[i]=r*X[i-1]-D;
    cout<<X[i]<<" "<<endl;
  }
  return 0;
}