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
  int N;
  cin >> N;
  vi A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vvi cnt(200010);
  rep(i,N) {
    cnt[A[i]].push_back(i);
  }
  vi dp(N+1,0);
  dp[0] = 1;
  rep(i,N) {
    int p = lower_bound(rng(cnt[A[i]]),i)-cnt[A[i]].begin();
    if(p+1 < sz(cnt[A[i]])) {
      int r = cnt[A[i]][p+1];
      if(r != i+1) {
        dp[r] += dp[i];
        dp[r] %= MOD;
      }
    }
    dp[i+1] += dp[i];
    dp[i+1] %= MOD;
  }
  cout << dp[N] << endl;

  return 0;
}