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

int check(string &s,string &t) {
  if(sz(s) != sz(t)) return sz(s) < sz(t) ? 1 : -1;
  rep(i,sz(s)) {
    if(s[i] != t[i]) return s[i] < t[i] ? 1 : -1;
  }
  return 0;
}
  
int main() {
  int N,M;
  cin >> N >> M;
  vi A(M);
  rep(i,M) {
    cin >> A[i];
  }
  vi cost = {2,5,5,4,5,6,3,7,6};
  v(string) dp(N+1,"");
  rep(i,N+1) {
    rep(c,M) {
      int x = cost[A[c]-1];
      if((i-x > 0 && dp[i-x] != "") || i-x == 0) {
        string t = dp[i-x] + to_string(A[c]);
        int res = check(dp[i],t);
        if(res < 1) continue;
        dp[i] = t;
      }
    }
  }
  cout << dp[N] << endl;
  return 0;
}