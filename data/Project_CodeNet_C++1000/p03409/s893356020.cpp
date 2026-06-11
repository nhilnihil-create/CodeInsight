#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using P = pair<int, int>;
const int INF = 1001001001;

int main(void){
  int n;
  cin >> n;
  set<P> red, blue;
  REP(i, n){
    int a, b;
    cin >> a >> b;
    red.insert(P(a, b));
  }
  REP(i, n){
    int c, d;
    cin >> c >> d;
    blue.insert(P(c, d));
  }

  int ans = 0;
  for(auto b : blue){
    P p(-1, -1);
    for(auto r : red){
      if(r.first < b.first && r.second < b.second){
        if(p.second < r.second) p = r;
      }
    }
    if(p == P(-1, -1)) continue;
    ans++;
    red.erase(p);
  }
  cout << ans << endl;
  return 0;
}