#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,K;
  cin>>N>>K;
  if(K%2==1){
    cout<<(N/K)*(N/K)*(N/K)<<endl;
  }
  else{
    cout<<(N/K)*(N/K)*(N/K)+((N+K/2)/K)*((N+K/2)/K)*((N+K/2)/K)<<endl;
  }
}