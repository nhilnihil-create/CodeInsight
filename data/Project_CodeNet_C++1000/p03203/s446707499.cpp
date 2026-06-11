#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define all(c) (c).begin(), (c).end()
#define debug(x) cerr << #x << " = " << x << endl
#define eb emplace_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int h,w,n;
  cin>>w>>h>>n;
  int ans = w;
  vector<pii> p(n);
  set<pii> blocked;
  rep(i,0,n) {
    cin>>p[i].X>>p[i].Y;
    blocked.insert(p[i]);
  }
  vi reach(w+1);
  reach[1] = 1;
  rep(i,2,w+1) {
    reach[i] = reach[i-1]+1;
    if(blocked.count({i, reach[i]})) --reach[i];
  }
  for(auto q:p) {
    if(reach[q.X] >= q.Y) {
      ans = min(ans, q.X-1);
    }
  }
  cout << ans << endl;
  return 0;
}
/*
 * T must ++x, otherwise A will pass to and end the game.
 * A has two choices:
 *  pass: y += 0
 *  move: ++y
 *
 * Wich block can we reach?
 *
 *  1234 x
 * 1....
 * 2 .X.
 * 3  ..
 * 4   .
 *
 * ...
 * ..X
 * ...
 *
 *
 *
 *
 */
