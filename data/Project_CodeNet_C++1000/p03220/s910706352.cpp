#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Z=0,B=0;
  cin>>N;
  int64_t T,A,K;
  cin>>T>>A;
  A*=1000;
  T*=1000;
  cin>>K;
  Z=abs(A-T+6*K);
  for(int i=1;i<N;i++){
    int64_t k;
    cin>>k;
    if(abs(A-T+6*k)<Z){
      Z=abs(A-T+6*k);
      B=i;
    }
  }
  B++;
  cout<<B<<endl;
}