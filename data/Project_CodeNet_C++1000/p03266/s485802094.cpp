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
  ll n,k,ans=0;cin>>n>>k;
  ll num=n/k;
  ans=num*num*num;
  if(k%2==0) {
    ll val=0;
    while(k*val+k/2<=n) val++;
    ans+=val*val*val;
  }
  print(ans);
  return 0;
}