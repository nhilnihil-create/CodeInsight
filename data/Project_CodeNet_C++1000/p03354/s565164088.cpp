#include <bits/stdc++.h>
#define INF pow(10, 9) + 7
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define chmax(x, y) x = max(x, y)
#define print(x) cout << x << "\n"
#define printv(vec) rep(i, vec.size()) cout << vec[i] << " "
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;

struct union_find{

  vl parent;

  void init(ll n) {
    rep(i, n) parent.push_back(i);
    return;
  }

  ll root(ll n){
    if(parent[n] == n) return n;
    return parent[n] = root(parent[n]);
  }

  bool is_same(ll a, ll b){
    return root(a) == root(b);
  }

  void unite(ll a, ll b){
    if(is_same(a, b)) return;
    parent[root(b)] = root(a);
    return;
  }
};

void solve(){
	
	ll N, M;
	cin >> N >> M;
	vl p(N);
	rep(i, N) cin >> p[i];
	vvl x(M, vl(2));
	rep(i, M) cin >> x[i][0] >> x[i][1];
	ll ans = 0;
	union_find uf;
	uf.init(N);
	rep(i, M) uf.unite(x[i][0] - 1, x[i][1] - 1);
	rep(i, N) ans += uf.is_same(i, p[i] - 1);
	print(ans);
}	

int main(){
    
    fastio;
	solve();
    
	return 0;
	
}
