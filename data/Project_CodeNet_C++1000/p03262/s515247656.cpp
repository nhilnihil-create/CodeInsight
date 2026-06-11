#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll n,x;
  cin>>n>>x;
  
  vector<ll> A(n);
  ll y;
  rep(i,n){
    cin>>y;
    A[i]=abs(y-x);
  }
  
  ll ans=A[0];
  for(int i=1;i<n;i++){
    ans=gcd(ans,A[i]);
  }
  cout<<ans<<endl;
  
  return 0;
}