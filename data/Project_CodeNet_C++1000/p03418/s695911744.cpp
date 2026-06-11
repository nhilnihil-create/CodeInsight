#include<bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (n); i++)
#define ll long long
using namespace std;

int main() {
  int n,k; cin>>n>>k;
  ll ans=0;
  rep(b, k+1, n+1) ans+=(n/b)*(b-k)+max(0, n%b-k+1);
  if (k==0) ans-=n;
  cout<<ans<<endl;
  return 0;
}
