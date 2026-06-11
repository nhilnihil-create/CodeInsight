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
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;
const int MAX_H = 101;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), h(n);
  rep(i, n) cin >> x[i] >> y[i] >> h[i];
  int cx, cy, H;
  rep(i, MAX_H) {
    rep(j, MAX_H) {
      cx = i, cy = j;
      auto f = [&](int nx, int ny, int nh){
        return nh + abs(nx - cx) + abs(ny - cy);
      };
      rep(k, n) if(h[k] > 0) H = f(x[k], y[k], h[k]);
      bool ok = true;
      rep(k, n) {
        int t = max(H - abs(x[k] - cx) - abs(y[k] - cy), 0);
        if(h[k] != t) ok = false;
      }
      if(ok) {
        cout << cx <<  " " << cy << " " << H << endl;
        return 0;
      }
    }
  }
}
