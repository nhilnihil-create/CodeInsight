// MOHIT KUMAR
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pin;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

#define ff(i, a, b) for ( ll i=a; i<(b); i++)
#define ffd(i, a, b) for ( ll i=a; i<= b; i++)
#define fr(i, a, b) for ( ll i = (b)-1; i >= a; i--)
#define ffr(i, a, b) for ( ll i = b ; i >= a; i--)
#define vl vector < ll >
#define vp vector < pl >
#define endl "\n"
#define sz(x) (ll)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const ld pi = acos(-1) ;
const ll maxn = 1e5 + 5 ;
const int mod = 1e9 + 7 ;
const ll INF = 1e10 ;
const int MX = 2000000001 ; // check the limits, dummy


int main() {
  ios_base::sync_with_stdio(0) , cin.tie(0);
  ll t, q, n, a, b, c, d, k, l, m, r,  x = 0, y = 0, z = 0 , sum = 0, ans = 0, temp = 0, res = 0 ;
  cin >> x >> y >> z >> k ;
  vl vx(x), vy(y), vz(z), vxy, vxyz ;
  for (auto &a : vx) cin >> a ;
  for (auto &a : vy) cin >> a ;
  for (auto &a : vz) cin >> a ;

  ff(i, 0, x) {
    ff(j, 0, y) vxy.pb(vx[i] + vy[j]) ;
  }
  sort(all(vxy), greater < ll > ()) ;
  ff(i, 0, min(k, sz(vxy))) {
    ff(j , 0 , z) vxyz.pb(vxy[i] + vz[j]) ;
  }
  sort(all(vxyz), greater < ll > ()) ;
  ff(i, 0, k) cout << vxyz[i] << endl ;
}