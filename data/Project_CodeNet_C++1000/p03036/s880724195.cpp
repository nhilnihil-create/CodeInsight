#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 int r,D,x;
 cin>>r>>D>>x;
 vector<int>X(100);X[0]=x;
 for(int i=1;i<=10;i++){
  X[i]=r*X[i-1]-D;
  cout<<X[i]<<endl;
 }
 return 0;}