#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define Rep(i,n) for(ll i = 0; i <= n; i++)
#define REp(i,n) for(ll i = 1; i < n; i++)
#define REP(i,n) for(ll i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
  int n, m;
  cin >> n >> m;
  V<V<int>> d(m,V<int>(m));
  V<V<int>> c(n,V<int>(n));
  rep(i,m)rep(j,m) cin >> d[i][j];
  rep(i,n)rep(j,n) cin >> c[i][j];
  // iwa[i][j] = グループjが色iの時に感じる違和感の総和
  // j = (x + y) % 3
  V<V<int>> iwa(m,V<int>(3));
  rep(i,n) {
    rep(j,n) {
      rep(ci,m) {
        iwa[ci][(i+j)%3] += d[c[i][j]-1][ci];
      }
    }
  }
  int ans = inf;
  rep(i,m)rep(j,m)rep(k,m) {
    if(i == j || j == k || k == i) continue;
    int tmp = iwa[i][0] + iwa[j][1] + iwa[k][2];
    chmin(ans, tmp);
  }
  cout << ans << endl;
}