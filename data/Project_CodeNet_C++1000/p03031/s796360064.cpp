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
# define mp make_pair
# define x first
# define y second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  int n, m; cin >> n >> m;
  vector<int> k(m);
  vector<vector<int>> s(m, vector<int>(0));
  rep(i, m){
    cin >> k[i];
    rep(j, k[i]){
      int a; cin >> a;
      a--;
      s[i].pb(a);
    }
  }
  vector<int> p(m);
  rep(i, m) cin >> p[i];

  int ans = 0;

  for(int i = 0; i < (1 << n); i++){
    bool flag = true;
    rep(j, m){
      int t = 0;
      rep(h, k[j]){
        if(i & (1 << (s[j][h]))) t++;
      }
      if(t%2 != p[j]) flag = false;
    }
    if(flag) ans++;
  }

  cout << ans << endl;
}
