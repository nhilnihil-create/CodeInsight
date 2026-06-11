#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) RFOR(i, n, 0)
#define MFOR(i, m) for(auto i=(m).begin();i!=(m).end();i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll << 50;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i] << " ";
  }
  cout << endl;
}


int main () {
  cin.tie(0);
  cout << setprecision(10);

  ll n, m; cin >> n >> m;
  vi d(n, 0);
  if(m == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  vector<vector<P>> g(n);
  REP(i, m) {
    int l, r, c; cin >> l >> r >> c;
    l--; r--;
    g[l].pb(P(r, c));
    g[r].pb(P(l, -c));
  }

  vector<bool> sel(n,false);
  vector<bool> stsel(n, false);
  bool ok = true;
  while(count(ALL(sel), false) && ok) {
    stack<int> st;
    int start = find(ALL(sel), false) - sel.begin();
    st.push(start);
    sel[start] = true;
    stsel[start] = true;
    while(!st.empty() && ok) {
      int now = st.top(); st.pop();
      REP(i, SZ(g[now])) {
        int next = g[now][i].fi, cost = g[now][i].se;
        if(sel[next] && d[now] + cost != d[next]) {
          ok = false;
          break;
        } else {
          d[next] = d[now] + cost;
        }
        sel[next] = true;
        if(!stsel[next]) st.push(next);
        stsel[next] = true;
      }
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  

  

}
