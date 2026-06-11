#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,M;
  cin>>N>>M;
  
  vector<vector<int>> vec(M,vector<int> (2));
  for(int i=0;i<M;i++){
    cin>>vec[i][0]>>vec[i][1];
  }
  
  vector<int> A(M);
  for(int i=0;i<M;i++){
    A[i]=vec[i][0];
  }
  
  vector<int> B(M);
  for(int i=0;i<M;i++){
    B[i]=vec[i][1];
  }
  
  int max_1=-1;
  
  int min_1=10000000;
  
  for(int i=0;i<M;i++){
    max_1=max(max_1,A[i]);
    
    min_1=min(min_1,B[i]);
  }
  
  
  int x=(min_1)-(max_1)+1;
  
  if(x>=0){
    cout<<x<<endl;
  }
  else{
    cout<<0<<endl;
  }
}
  