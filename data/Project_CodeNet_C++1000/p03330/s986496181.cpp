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

int d[30][30];
int main() {
  int n,c;
  cin >> n >> c;
  rep(i,c)rep(j,c) cin >> d[i][j];
  vector<vector<ll>> v(3,vector<ll>(c));
  rep(i,n)rep(j,n){
    int k = (i+j)%3;
    int s;
    cin >> s;
    --s;
    rep(t,c) v[k][t] += d[s][t];
  }

  ll ans = 1e18L;
  rep(i,c)rep(j,c)rep(k,c){
    if(i==j||j==k||k==i) continue;
    ans = min(ans,v[0][i]+v[1][j]+v[2][k]);
  }
  cout << ans << endl;
}