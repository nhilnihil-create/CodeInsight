#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll p[8][3] = {
  {1,1,1},
  {1,1,-1},
  {1,-1,1},
  {1,-1,-1},
  {-1,1,1},
  {-1,1,-1},
  {-1,-1,1},
  {-1,-1,-1},
};

int main() {
  int n,m;
  cin >> n >> m;

  vector<vector<ll>> v(8,vector<ll>(n));
  rep(i,n){
    ll x,y,z;
    cin >> x >> y >> z;
    rep(j,8){
      v[j][i] = x*p[j][0] + y*p[j][1] + z*p[j][2];
    }
  }
  ll ans = 0;
  rep(j,8){
    sort(v[j].rbegin(),v[j].rend());
    ll res = 0;
    rep(i,m) res += v[j][i];
    ans = max(ans,res);
  }
  cout << ans << endl;
}