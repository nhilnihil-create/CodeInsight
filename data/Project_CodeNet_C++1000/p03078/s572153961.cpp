#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

int main(){
  ll x,y,z,k;cin >> x >> y >> z >> k;
  vl a(x),b(y),c(z);
  rep(i,x)cin >> a[i];
  rep(i,y)cin >> b[i];
  rep(i,z)cin >> c[i];

  sort(c.begin(),c.end());
  
  vl ab(x*y);
  rep(i,x)rep(j,x)ab[x*i+j]=a[i]+b[j];
  sort(ab.rbegin(),ab.rend());
  priority_queue<ll> ans;
  rep(i,min(k,x*y))rep(j,min(k,z)){
    ans.push(ab[i]+c[j]);
  }
  rep(i,k){printf("%lld\n",ans.top());ans.pop();}
}