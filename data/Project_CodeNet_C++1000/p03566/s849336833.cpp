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

ll n;
ll t[e5];
ll v[e5];
ll x;
ll speed;
ll max_speed_l[e5];
ll max_speed_r[e5];
ll max_speed[e5];
ll ans;

int main(){
  cout << setprecision(17);
  cin >> n;
  for(ll i = 1;i <= n;i++) cin >> t[i];
  for(ll i = 1;i <= n;i++) cin >> v[i];
  for(ll i = 1;i <= n;i++) t[i] *= 2;
  for(ll i = 1;i <= n;i++) v[i] *= 2;
  for(ll i = 1;i <= n;i++) t[i] += t[i-1];
  x = 0;
  speed = 0;
  for(ll i = 1;i <= n;i++){
    for(;x < t[i];x++){
      max_speed_l[x] = speed;
      speed = min(speed+1,v[i]);

    }
  }
  x = t[n];
  speed = 0;
  for(ll i = n;i >= 1;i--){
    for(;x > t[i-1];x--){
      max_speed_r[x] = speed;
      speed = min(speed+1,v[i]);
    }
  }
  for(ll x = 0;x <= t[n];x++){
    max_speed[x] = min(max_speed_l[x],max_speed_r[x]);
  }
  for(ll x = 0;x < t[n];x++){
    ans += max_speed[x]+max_speed[x+1];
  }
  printf("%lf\n", ans/8.0);
  // cout << setprecision(17) << ans/8.0 << endl;;

}
