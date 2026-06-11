#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main() {
  ll n,k;
  cin>>n>>k;
  ll ans=0;
  for (ll b=k+1; b<=n; b++) {
    ans+=(n+1)/b*(b-k);
    ans+=max(0ll,(n+1)%b-k);
  }
  if (k==0) ans-=n;
  cout<<ans<<endl;
  return 0;
}


