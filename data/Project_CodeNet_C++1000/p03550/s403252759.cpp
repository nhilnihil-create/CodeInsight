#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll n,z,w; cin>>n>>z>>w;
  vector<ll> a(n);
  for (int i=0;i<n;i++) cin>>a[i];
  ll ans=abs(w-a[n-1]);
  if (n!=1) ans=max(ans, abs(a[n-1]-a[n-2]));
  cout<<ans<<endl;
  return 0;
}