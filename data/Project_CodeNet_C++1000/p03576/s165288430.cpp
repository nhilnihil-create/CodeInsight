#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;
  
int main() {
  int N,K;
  cin >> N >> K;
  vp xy(N);
  rep(i,N) {
    int x,y;
    cin >> x >> y;
    xy[i] = P(x,y);
  }
  sort(rng(xy));
  ll ans = 1ll<<62;
  rep(i,N) {
    int x1 = xy[i].first;
    rep(j,N) {
      int x2 = xy[j].first;
      rep(k,N) {
        int y1 = xy[k].second;
        rep(l,N) {
          int y2 = xy[l].second;
          int cnt = 0;
          rep(a,N) {
            int x = xy[a].first;
            int y = xy[a].second;
            if(x1 <= x && x <= x2 && y1 <= y && y <= y2) {
              cnt++;
            }
          }
          if(cnt >= K) {
            ans = min(ans,1ll*(y2-y1)*(x2-x1));
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}