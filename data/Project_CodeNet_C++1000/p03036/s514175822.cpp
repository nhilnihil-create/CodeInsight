#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int r,D,x_0;
  cin>>r>>D>>x_0;
  
  
  vector<long long> x(11);
  x[0]=x_0;
  for(int i=0;i<10;i++){
    x[i+1]=x[i]*r-D;
  }
  
  for(int i=1;i<11;i++){
    cout<<x[i]<<endl;
  }
}