#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll,ll>;

using pqg = priority_queue<ll,vector<ll>, greater<ll> >; // 1,3,5..
using pql = priority_queue<ll,vector<ll> >; //5, 3, 1...

using pqg_p = priority_queue<P,vector<P>, greater<P> >; // 1,3,5..
using pql_p = priority_queue<P,vector<P> >; //5, 3, 1...

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define REPS(i,s,n) for(auto i=s, i##_len=(n); i<i##_len; ++i)

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(a)  (a).begin(),(a).end()

int H,W;


int main() {
	cin.tie(0);
  ios::sync_with_stdio(false);

  int c[100][100];
  cin >> H  >> W;

  //0 dame
  //1 koori

  int white = 0;

  REP(i,H) {
    c[i+1][0] = 0;
    c[i+1][W+1] = 0;
    REP(j,W) {
      char _c;
      cin >> _c;
      if (_c == '#') c[i+1][j+1] = -1;
      else {
        c[i+1][j+1] = -2;
        white++;
      }
    }
  }
  REP(i,W+2) {
    c[0][i] = -1;
    c[H+1][i] = -1;
  }


  queue<P> q;
  q.push(MP(1,1));
 
  c[1][1] = 0;
 
  int cy[4] = {0,1,0,-1};
  int cx[4] = {1,0,-1,0};
  for(;;) {
    if (q.empty()) break;
    auto d = q.front();
    q.pop();
    if (d.S == W && d.F == H) break;
 
    REP(i,4) {
      int ny = d.F + cy[i];
      int nx = d.S + cx[i];
      if (c[ny][nx] == -2 ) {
        c[ny][nx] = c[d.F][d.S] + 1;
        q.push(MP(ny,nx));
      }
    }
  }

  //REP(ii,N+2) { REP(jj,M+2) { cout << tmp[ii][jj] << " " ; } cout << endl;}
  

  cout << (c[H][W] == -2?-1: white - c[H][W] -1) << endl;



  return 0;

}
