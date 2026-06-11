#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
//#include <tuple>
#include <iomanip>
#include <cstring>

using namespace std;

typedef long long ll;
//typedef pair<int,int> Pint;
//typedef pair<ll, ll> P;
typedef pair<ll, pair<ll, ll> > P;
//typedef tuple<int,int,int> T;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n-1); i >= 0; i--)
#define pb push_back
#define f first
#define s second
const ll INFL = 1LL << 60;//10^18 = 2^60
const int INF = 1 << 30;//10^9
const ll MOD = 1e9 + 7;
//const ll MOD  = 998244353;
//vector<ll> dy = {0, 0, 1, -1, 1, 1, -1, -1, 0};
//vector<ll> dx = {1, -1, 0, 0, 1, -1, 1, -1, 0};

ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}

const ll N_ = (1 << 18);
ll seg[2*N_-1];
//Range Minimum Query
void update(ll k, ll x){
  k += N_-1;
  seg[k] = x;
  while(k > 0){
    k = (k-1)/2;
    seg[k] = min(seg[2*k+1], seg[2*k+2]);
  }
}

ll query(ll x, ll y, ll k, ll left, ll right){
  if(right <= x || y <= left) return INFL;
  if(x <= left && right <= y) return seg[k];
  ll mid = (left + right) / 2;
  ll l = query(x, y, 2*k+1, left, mid);
  ll r = query(x, y, 2*k+2, mid, right);
  return min(l, r);
}

ll N, K, Q;
vector<ll> A;

int main(void){
  cin >> N >> K >> Q;
  A.resize(N);
  rep(i, N) cin >> A[i];
  rep(i, N) update(i, A[i]);
  ll ans = INFL;
  rep(i, N){
    vector<pair<ll, ll>> can;
    rep(j, N){
      ll k = j + K;
      if(query(j, k, 0, 0, N_) >= A[i]){
        while(query(j, k+1, 0, 0, N_) >= A[i]) k++;
        can.pb({j, k});
        j = k-1;
      }
    }

    ll cnt = 0;
    rep(j, can.size()) cnt += (can[j].s - can[j].f) - K + 1;

    if(cnt < Q) continue;
    vector<ll> xs[can.size()];
    rep(j, can.size()) for(ll k = can[j].f; k < can[j].s; k++) xs[j].pb(A[k]);
    rep(j, can.size()) sort(xs[j].begin(), xs[j].end());
    vector<ll> canGet;
    rep(j, can.size()) rep(k, xs[j].size() - K + 1) canGet.pb(xs[j][k]);
    sort(canGet.begin(), canGet.end());
    ans = min(ans, canGet[Q-1] - A[i]);
  }
  cout << ans << endl;
}
