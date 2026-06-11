#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  vector <long long> A(N+2,0);
  vector <long long> L(N+2,0);
  vector <long long> R(N+2,0);
  for(long long i=0;i<N;i++){
    cin>>A[i];
  }
  L[0]=0;
  for(long long i=1;i<=N;i++){
    L[i]=gcd(L[i-1],A[i-1]);
  }
   R[N+1]=0;
  for(long long i=N;i>=0;i--){
    R[i]=gcd(R[i+1],A[i]);
  }  
    long long maxgcd=0;
  long long temp=0;
  for(long long i=0;i<N;i++){
    temp=gcd(L[i],R[i+1]);
    maxgcd=max(maxgcd,temp);
    //cout<<i<<" "<<L[i]<<" "<<R[i]<<" "<<temp<<endl;
  }
  cout<<maxgcd<<endl;
  
  return 0;
}

       