#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<long long> A(N),B(N),C(N);
  long long sum=0;
  for(int i=0; i<N; i++){
    cin >> A[i] >> B[i];
    C[i]=A[i]+B[i];
    sum-=B[i];
  }
  
  sort(C.begin(),C.end(),greater<long long>());
  
  for(int i=0; i<(N+1)/2; i++){
    sum+=C[i*2];
  }
  cout << sum << endl;
}