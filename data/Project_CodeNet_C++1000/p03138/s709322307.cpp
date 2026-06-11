#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; i++)
#define ll long long
using namespace std;

int main() {
  int n; cin>>n;
  ll k; cin>>k;
  vector<ll> A(n);
  rep(i, n) cin>>A[i];
  ll res=0;
  for (int i=40; i>=0; --i) {
    ll one=0;
    rep(j, n) one+=(1&(A[j]>>i));
    ll zero=n-one;
    if (k>=(1LL<<i)&&one<zero) {
      k-=1LL<<i;
      res+=zero<<i;
    }
    else res+=one<<i;
  }
  cout<<res<<endl;
}
