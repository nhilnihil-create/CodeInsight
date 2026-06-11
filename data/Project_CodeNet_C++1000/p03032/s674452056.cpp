#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<ll> V(n);
  rep(i,n) cin >> V[i];
  ll ans = -INF;
  for (int l = 0; l <= min(n,k) ; l++) {
    for (int r = 0; r <= min(n,k) ; r++){
      if (l + r > n || l + r > k) continue;
      vector<ll> v;
      ll rec = 0;
      rep(i, l) v.pb(V[i]);
      rep(i, r) v.pb(V[n - 1 - i]);
      sort(all(v));
      rep(i, sz(v)) rec += v[i];
      rep(i, min(sz(v),k - l - r)) {
        if (v[i] < 0) rec -= v[i];
      }
      chmax(ans, rec);
    }
  }
  cout << ans << endl;
  return 0;
}