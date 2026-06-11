#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll,ll>;

using DV = vector<vector<ll>>;

using pqg = priority_queue<ll,vector<ll>, greater<ll> >; // 1,3,5..
using pql = priority_queue<ll,vector<ll> >; //5, 3, 1...

using pqg_p = priority_queue<P,vector<P>, greater<P> >; // 1,3,5..
using pql_p = priority_queue<P,vector<P> >; //5, 3, 1...

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)

#define F first
#define S second
#define PB push_back
#define MP make_pair




int main() {
	cin.tie(0);
  ios::sync_with_stdio(false);

  int V,H,W;

  cin >> H >> W;

  V = 10;

  ll d[V][V];

  ll inf = 100000000000;

  REP(i,V) {
    REP(j,V) {
      ll c;
      cin >> c;

      d[i][j] = c;
    }
  }


  REP(k,V) {
    REP(i,V) {
      REP(j,V) {
        if(d[i][k] == inf || d[k][j] == inf) continue;
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  ll ans = 0;
  REP(h,H) {
    REP(w,W) {
      ll c;
      cin >> c;
      if (c == -1 ) continue;
      ans += d[c][1];
    }   
  }

  cout << ans << endl;




}
