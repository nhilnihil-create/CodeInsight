#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  
    vector<double> A(N);
  vector<string> B(N);
  for(int i=0;i<N;i++){
  cin>>A[i]>>B[i];
  }
  double a=0;
  for(int i=0;i<N;i++){
  if(B[i]=="BTC"){
  a+=A[i]*380000.0;
  }
    if(B[i]=="JPY"){
    
    a+=A[i];
    }
  }
  cout<<a<<endl;
  
  }
  
