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

int main() {
  int n;
  cin >> n;
  vector<ll> x(n), y(n), h(n);
  rep(i, n) cin >> x[i] >> y[i] >> h[i];
  ll ansh = 0;
  pair<int, int> p;
  int idxh = 0;
  rep(i, n) {
    if(h[i] > 0) idxh = i;
  }
  rep(cx, 101) {
    rep(cy, 101) {
      bool ok = true;
      ll H = h[idxh] + abs(x[idxh] - cx) + abs(y[idxh] - cy);

      rep(i, n) {
        ll hh = max(H - abs(x[i] - cx) - abs(y[i] - cy), 0LL);
        if (hh != h[i]) ok = false;
      }
      if (ok && ansh < H) {
        p.first = cx;
        p.second = cy;
        ansh = H;
      }
    }
  }
  cout << p.first << " " << p.second << " " << ansh << endl;
}