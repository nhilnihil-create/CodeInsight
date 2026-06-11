// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a); i<(b);++i)
#define rep(i, n) FOR(i, 0, n)

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

// solve

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  vector<ll> x, y;
  bool flag = true;
  int oe = 0;
  rep(i, n){
    ll a, b;
    cin >> a >> b;
    x.pb(a);
    y.pb(b);
    if(i == 0){
      oe = (a + b) % 2;
      if(oe < 0)oe += 2;
    }else{
      int toe = (a + b) % 2;
      if(toe < 0)toe += 2;
      if(oe != toe){
        flag = false;
      }
    }
  }
  if(!flag){
    cout << - 1 << endl;
    return 0;
  }
  // add R
  int res = 36;
  if(oe == 0){
    res++;
    rep(i, n){
      x[i]--;
    }
  }
  vector<string> ans(n);
  rep(i, n){
    vector<int> up, vp;
    ll u = x[i] + y[i];
    ll v = x[i] - y[i];
    for(int j = 35; j >= 0; j--){
      ll base = (ll)1 << j;
      if(u > 0){
        up.pb(1);
        u = u - base;
      }else{
        up.pb(-1);
        u = base + u;
      }
      if(v > 0){
        vp.pb(1);
        v = v - base;
      }else{
        vp.pb(-1);
        v = base + v;
      }
    }
    rep(j, up.size()){
      if(up[j] == 1 && vp[j] == 1)ans[i] += "R";
      else if(up[j] == 1 && vp[j] == -1)ans[i] += "U";
      else if(up[j] == -1 && vp[j] == 1)ans[i] += "D";
      else ans[i] += "L";
    }
  }
  cout << res << endl;
  if(res == 37)cout << 1 << " ";
  for(int i = 35; i >= 0; i--){
    cout << ((ll)1 << i);
    if(i != 0)cout << " ";
    else cout << endl;
  }
  rep(i, n){
    if(res == 37)cout << "R";
    cout << ans[i] << endl;
  }

//   rep(i, n){
//     ll basex = 0, basey = 0;
//     if(res == 37)basex++;
//     for(int j = 35; j >= 0; j--){
//       ll base = (ll)1 << j;
//       if(ans[i][35-j] == 'L')basex -= base;
//       else if(ans[i][35-j] == 'R')basex += base;
//       else if(ans[i][35-j] == 'U')basey += base;
//       else basey -= base;
//     }
//     cout << basex << " " << basey << endl;
//   }
	return 0;
}
