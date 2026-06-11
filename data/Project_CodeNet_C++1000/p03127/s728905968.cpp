#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  
  vector<ll> A(n);
  rep(i,n) cin>>A[i];
  
  ll ans=A[0];
  for(int i=1;i<n;i++){
    ans=gcd(ans,A[i]);
  }
  
  cout<<ans<<endl;

  return 0;
}