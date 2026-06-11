#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  
  vector<int> A(n),B(n),C(n);
  rep(i,n) cin>>A[i];
  rep(i,n) cin>>B[i];
  rep(i,n) cin>>C[i];
  sort(ALL(A));
  sort(ALL(C));
  
  ll a,c;
  ll ans=0;
  rep(i,n){
    a=lower_bound(ALL(A),B[i])-A.begin();
    c=C.end()-upper_bound(ALL(C),B[i]);
    ans+=a*c;
  }
  cout<<ans<<endl;

  return 0;
}