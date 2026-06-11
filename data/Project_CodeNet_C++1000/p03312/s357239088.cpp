#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1e18;
int main(){
  ll N; cin >> N;
  vector<ll> sum(N+1,0);
  REP(i,N) {
    ll a; cin >> a;
    sum[i+1] = sum[i] + a;
  }

  //a[l]...a[r]を総和の差の絶対値が最小となるよう2分割する
  //sum_max, sum_minに総和の最大値，最小値を返す
  auto divide_array = [&](ll l, ll r, ll& sum_max, ll& sum_min){
    ll T = sum[r] - sum[l-1];
    auto it = upper_bound(sum.begin()+l, sum.begin()+r+1,T/2+sum[l-1]);
    REP(i,2){
      ll U = *it - sum[l-1];
      chmin(sum_max, max(U, T - U));
      chmax(sum_min, min(U, T - U));
      if(it != sum.begin()+l)it--;
    }
  };

  ll ans = 1e18;
  FOR(b,2,N-1){
    vector<ll> p(4,0);
    p[0] = INF, p[2] = INF;
    divide_array(1,b, p[0], p[1]);
    divide_array(b+1,N, p[2],p[3]);
    sort(ALL(p));
    chmin(ans, p[3]-p[0]);
  }
  cout << ans << endl;
}