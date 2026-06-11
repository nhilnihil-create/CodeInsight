#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,K;
  cin>>N>>K;
  cout<<(N/K)*(N/K)*(N/K)+(1-K%2)*((N+K/2)/K)*((N+K/2)/K)*((N+K/2)/K)<<endl;
}