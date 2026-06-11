#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ALL(a) (a).begin(), (a).end()
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define rep(i, n) FOR(i, 0, n)
#define repi(i, n) FOR(i, 1, n + 1)
#define pp(v) cerr << #v "=" << (v) << endl;
#define ppa(v) cerr << "- " << #v << endl; rep(i,v.size()) cerr << #v << "[" << i << "] = " << v[i] << endl;
#define div_ceil(a,b) ((a) + ((b) - 1)) / (b)
#define UNIQUE(v) v.erase( unique(ALL(v)), v.end() );
#define INF 0x3f3f3f3f
#define LLINF 1000111000111000111LL
#define MOD 1000000007
#define TIME system("date +%M:%S.%N")
using Graph = vector<vector<int>>;
using ll = long long;
template<class T> T gcd(const T &a, const T &b) { return a < b ? gcd(b, a) : b ? gcd(b, a % b) : a; }
template<class T> T lcm(const T &a, const T &b) { return a / gcd(a, b) * b; }

#define x first
#define y second
#define mp make_pair
using Pos = pair<int,int>;
#define ppp(v) cerr << #v << "(" << v.x << "," << v.y << ")"
#define cr cerr << endl;

int main() {
  int n;cin>>n;
  vector<Pos> red(n);
  vector<Pos> blue(n);
  vector<bool> done(n,false); // red flag : true = 処理, false = 未処理
  rep(i,n) {
    int a,b;cin>>a>>b;
    red[i] = mp(a,b);
  }
  rep(i,n) {
    int a,b;cin>>a>>b;
    blue[i] = mp(a,b);
  }
  sort(ALL(blue));

  int ans = 0;
  rep(i,n) {
    Pos p = blue[i];
    Pos q = mp(-1,-1);
    int idx = -1;
    rep(j,n) {
      if (done[j]) continue;
      Pos r = red[j];
      if (r.x < p.x && r.y < p.y && q.y < r.y) {
        q = r;
        idx = j;
      }
    }
    if (idx != -1) {
      ans++;
      done[idx] = true;
    } 
  }

  cout << ans << endl;
}
