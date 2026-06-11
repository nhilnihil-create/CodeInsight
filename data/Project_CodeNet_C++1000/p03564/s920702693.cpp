#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
  int N,K;
  cin>>N>>K;
  int ans=1;
  while(N--){
   ans=min(ans*2,ans+K);
  }
  cout<<ans<<endl;
return 0;}