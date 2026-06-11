#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  vector<bool> A(100001,true);
  A[0]=false,A[1]=false;
  for(int i=2;i<=320;i++){
    if(!A[i])
      continue;
    for(int j=2;i*j<=100001;j++)
      A[i*j]=false;
  }
  vector<int> B(100002,0);
  for(int i=3;i<100002;i+=2){
    B[i+1]=B[i-1];
    if(A[i] && A[(i+1)/2])
      B[i+1]++;
  }
  int Q;
  cin>>Q;
  for(int i=0;i<Q;i++){
    int l,r;
    cin>>l>>r;
    cout<<B[r+1]-B[l-1]<<endl;
  }
}