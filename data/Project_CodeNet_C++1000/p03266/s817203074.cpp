#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N>>K;
  long ans;
  if(K%2!=0){    
    ans=((long)N/K)*((long)N/K)*((long)N/K);
  }
  else{
    ans=((long)N/K)*((long)N/K)*(N/K)+((long)2*N/K-N/K)*((long)2*N/K-N/K)*((long)2*N/K-N/K);
  }
   cout<<ans<<endl;
}