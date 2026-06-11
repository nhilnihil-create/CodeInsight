#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  ll D,N;
  cin>>D>>N;
  bool a=true;
  ll ans=0;
  if(N!=100){
      ans=N;
  }
  else{
      ans=101;
  }
  cout<<ll(ans*ll(pow(100,D)))<<endl;
}