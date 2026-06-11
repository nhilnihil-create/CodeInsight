#include <iostream> // cout, endl, cin
#include <cmath> //sqrt pow
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // dequef
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower

#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> x(n), y(n);
  //vector<ll> defx(n), defy(n);
  map<pii, int> board;
  rep(i, n){
    cin >> x[i] >> y[i];
    board[make_pair(y[i], x[i])] = 1;
  }
  sort(all(x)); sort(all(y));
  ll ans = (x[n - 1] - x[0]) * (y[n - 1] - y[0]);
  vector<vector<ll>> rui(n + 1, vector<ll>(n + 1));
  rep(dx, n){
    rep(dy, n){
      rui[dy + 1][dx + 1] = rui[dy][dx + 1] + rui[dy + 1][dx] - rui[dy][dx] + board[make_pair(y[dy], x[dx])];
    }
  }
  rep(dx, n){
    for(ll ddx = dx; ddx < n; ddx++){
      rep(dy, n){
        for(ll ddy = dy; ddy < n; ddy++){
          ll num = rui[ddy + 1][ddx + 1] - rui[dy][ddx + 1] - rui[ddy + 1][dx] + rui[dy][dx];
          if(num >= k) ans = min(ans, (x[ddx] - x[dx]) * (y[ddy] - y[dy]));
        }
      }
    }
  }
  cout << ans << endl;
}