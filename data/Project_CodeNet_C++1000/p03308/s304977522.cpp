#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++) {
cin>>A[i];
  }
  sort(all(A));
  cout<<A.back()-A[0]<<endl;
}
  