#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
  
  int c;
  c=a%b;
  a=b;
  b=c;
  
  if(c==0){
    return a;
  }else{
    return GCD(a, b);
  }
}

int main(){
  
  int N, i, j, mn=1000000000;
  cin>>N;
  vector<int> A(N);
  for(i=0; i<N; i++) cin>>A[i];
  for(i=0; i<N-1; i++){
    mn=min(mn, GCD(A[i], A[i+1]));
  }
  cout<<mn<<endl;
  return 0;
}