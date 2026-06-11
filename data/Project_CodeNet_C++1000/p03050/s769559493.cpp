#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
#define rep1(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";

int main(){
  ll n; cin >> n;
  ll ans=0;
  for(ll p=1;p*p<n; p++){
    if(n%p!=0) continue;
    ll m = n/p -1;
    if(m>p) ans+=m;
  }
  printf("%lld",ans);
  return 0;
}