#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

int main() { 
  int h,w,d;
  cin >> h >> w >> d;
  vector<P> mp(h*w);
  vi cost(h*w,-1);
  rep(i,h){
    rep(j,w){
      int id;
      cin >> id;
      id--;
      mp[id] = P(i,j);
    }
  }
  rep(i,d)cost[i] = 0;
  rep(i,d){
    for(int j = i;j<h*w;j+=d){
      if(j+d>=h*w) continue;
      int diff = abs(mp[j].fi - mp[j+d].fi)+abs(mp[j].se-mp[j+d].se);
      cost[j+d] = cost[j]+diff;
    }
  }
  //rep(i,h*w)show(cost[i]);
  int q;
  cin >> q;
  vi ans;
  rep(i,q){
    int l,r;
    cin >> l >> r;
    l--;r--;
    ans.push_back(cost[r]-cost[l]);
  }
  for(auto e : ans)cout<<e<<endl;
  return 0;
}