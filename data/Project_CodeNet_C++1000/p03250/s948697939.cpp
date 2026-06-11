#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define P pair<ll,ll>
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  lvector a(3,0);rep(i,3) cin>>a[i];
  sort(a.begin(),a.end());
  ll ans=a[2]*10+a[1]+a[0];
  print(ans);
  return 0;
}
