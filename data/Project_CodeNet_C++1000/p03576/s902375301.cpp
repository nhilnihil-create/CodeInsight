#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const ll INF = LLONG_MAX;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  ll ans = INF;
  
  rep(sx, n)rep(sy, n)rep(i, n) rep(j, n) {
    ll cnt = 0;
    ll startx = x[sx], starty = y[sy];
    ll endx = x[i], endy = y[j];
    if(startx > endx) swap(startx, endx);
    if(starty > endy) swap(starty, endy);
    rep(k, n) {
      ll nx = x[k], ny = y[k];
      if(startx <= nx && nx <= endx && starty <= ny && ny <= endy) cnt++;
    }
    if (cnt >= k) chmin(ans, (endx - startx) * (endy - starty));

  }
  cout << ans << endl;
}