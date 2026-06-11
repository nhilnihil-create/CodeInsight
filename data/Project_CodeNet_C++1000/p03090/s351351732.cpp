#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  vector<P> ans;
  if(n%2==0) {
    for(ll x=1;x<n;++x) {
      for(ll y=x+1;y<=n;++y) {
        if(x+y==n+1) continue;
        else ans.emplace_back(P(x,y));
      }
    }
  }
  else {
    for(ll x=1;x<n-1;++x) {
      for(ll y=x+1;y<n;++y) {
        if(x+y==n) continue;
        else ans.emplace_back(P(x,y));
      }
    }
    for(ll x=1;x<=n-1;++x) ans.emplace_back(P(x,n));
  }
  print(ans.size());
  for(P p:ans) cout<<p.first<<' '<<p.second<<endl;
  return 0;
}