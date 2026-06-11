#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  vector<ll> A(3);
  for(ll i=0;i<3;i++) {
cin>>A[i];
  }
  sort(all(A));
  cout<<A[2]-A[0]<<endl;
}
