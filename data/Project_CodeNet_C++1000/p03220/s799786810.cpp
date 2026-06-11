#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,T,A;
  cin>>N>>T>>A;
  T*=1000,A*=1000;
  int k=100000000,l=0;
  for(int i=1;i<=N;i++){
    int H;
    cin>>H;
    if(k>abs(A-(T-H*6))){
      k=abs(A-(T-H*6));
      l=i;
    }
  }
  cout<<l<<endl;
}