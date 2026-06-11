#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;

const ll e5 = 1 << 21;
const ll mod = 1000000007;
const ll e3 = 1 << 13;
const ll INF = 1ll << 62;

ll h,w,n;
set<vl> s;
ll l[e5];
ll ans;

int main(){
  cin >> w >> h >> n;
  for(ll i = 0;i < n;i++){
    vl p(2);
    cin >> p[1] >> p[0];
    s.insert(p);
  }
  for(ll i = 1;i <= h;i++){
    s.insert(vl({i,w+1}));
  }
  ans = w;
  l[1] = 1;
  for(ll i = 2,j = 1;i <= w;i++){
    if(s.count(vl({j+1,i})) == 0) j++;
    l[j] = i;

  }
  for(ll i = 1;i <= h;i++){
    if(l[i] == 0) break;
    vl p = *s.lower_bound(vl({i,l[i]}));
    // cerr << i << " " << l[i] << " " << p[0] << " " << p[1] << endl;
    ans = min(ans,p[1]-1);
  }
  cout << ans << endl;
}
