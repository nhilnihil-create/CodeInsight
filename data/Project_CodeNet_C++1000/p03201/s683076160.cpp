#include <bits/stdc++.h>
using namespace std;;
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
const int MOD = 1000000007;
 
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;

ll po2(ll x){
  ll ret = 1;
  while(ret<=x){
    ret *= 2;
  }
  return ret;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin >> n;
  map<ll, ll> s;
  rep(i,n){
    ll x;cin >> x;
    s[x]++;
  }
  ll ans = 0;
  while(s.size()){
    auto it = --s.end();
    ll x = it->first;
    ll y = po2(x) - x;
    if(x==y){
      ans += (it->second)/2;
      s.erase(it);
    }else{
      if(y>x)break;
      auto itt = s.find(y);
      if(itt!=s.end()){
        ll nu = it->second;
        ll num = itt->second;;
        ll mn = min(nu,num);
        ans += mn;
        itt->second -= mn;
      }
      s.erase(it);
    }
    cerr << x << " " << ans << endl;
  }
  cout << ans << endl;
}

