# include <bits/stdc++.h>
# define rep(i, n) for(ll i = 0; i < (n); ++i)
# define reps(i, n) for(ll i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(ll i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(ll i=((int)(n)); i>0; --i)
# define ll long long
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define P pair<int, int>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll lmax(ll a, ll b){if(a>= b) return a;return b;}
ll lmin(ll a, ll b){if(a>= b) return b;return a;}
static const ll INF = 1e18;

ll dp[52][102];

int main() {
  int n, k; cin >> n >> k;
  vector<int> v(n);
  rep(i, n) {
    cin >> v[i];
  }

  int ans = 0;
  for(int i = 0; i <= k; i++){
    for(int j = 0; j <= k - i; j++){
      if(i + j > n) continue;
      vector<int> a;
      int sum = 0, d = k - i - j;
      rep(x, i){
        sum += v[x];
        a.pb(v[x]);
      }
      rep(x, j){
        sum += v[n - 1 - x];
        a.pb(v[n - 1 - x]);
      }
      sort(ALL(a));
      for(int x = 0; x < d; x++){
        if(x >= a.size()) break;
        if(a[x] > 0) break;
        sum -= a[x];
      }
      chmax(ans, sum);
    }
  }

  cout << ans << endl;
}
