#include<bits/stdc++.h>
using namespace std;

int main(){
  int r,D,x;
  cin>>r>>D>>x;
  vector<int> xx(100000);
  xx[2000]=x;
  for(int i=2000; i<=2010; i++){
    xx[i+1]=r*xx[i]-D;
  }
  for(int i=2001; i<=2010; i++){
    cout<<xx[i]<<endl;
  }
}