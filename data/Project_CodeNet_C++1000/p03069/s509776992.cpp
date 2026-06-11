#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define P pair<ll,ll> 
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,ans=1e9;cin>>n;
  string s;cin>>s;
  lvector Sb(n+1,0);
  rep(i,n) Sb[i+1]=Sb[i]+((s[i]=='#')?1:0);
  ll nblack=Sb[n];
  rep(i,n+1) {
    ll cost=Sb[i]+n-i-(nblack-Sb[i]);
    ans=min(ans,cost);
  }
  print(ans);
  return 0;
}