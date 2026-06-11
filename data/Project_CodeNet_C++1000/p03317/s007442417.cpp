#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
#define MOD 1000000007;
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
int main() {
  
  int N,K;
  cin>>N>>K;
  
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  
  cout<<(N-2)/(K-1)+1<<endl;
}