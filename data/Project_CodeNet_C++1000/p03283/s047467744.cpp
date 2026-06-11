#include <bits/stdc++.h>
#define INF 100000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
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

vvl d2_add(vvl a){
	ll w, h, cnt_w;
	w = a[0].size();
	h = a.size();
	vvl da(h, vl(w));
	da[0][0] = a[0][0];
	rep2(i, 1, w)  da[0][i] = da[0][i - 1] + a[0][i];
	rep2(i, 1, h){
		cnt_w = 0;
		rep(j, w){
			cnt_w += a[i][j];
			da[i][j] = da[i - 1][j] + cnt_w;
		}
	}
	return da;
}

ll d2_calc(vvl& da, ll x1, ll y1, ll x2, ll y2){
	if(x1 > x2 || y1 > y2)  return 0;
	if(x1 == 0 && y1 == 0)  return da[x2][y2];
	if(x1 == 0)  return da[x2][y2] - da[x2][y1 - 1];
	if(y1 == 0)  return da[x2][y2] - da[x1 - 1][y2];
	return da[x2][y2] - da[x1 - 1][y2] - da[x2][y1 - 1] + da[x1 - 1][y1 - 1];
}

void solve(){
	
	ll N, M, Q, a, b, ans;
	cin >> N >> M >> Q;
	vvl v(N, vl(N));
	vvl p(Q, vl(2));
	
	rep(i, M){
		cin >> a >> b;
		v[a - 1][b - 1] += 1;
	}
	
	rep(i, Q){
		cin >> a >> b;
		p[i][0] = a - 1;
		p[i][1] = b - 1;
	}
	
	vvl ret = d2_add(v);
	
	rep(i, Q){
		ans = d2_calc(ret, p[i][0], p[i][0], p[i][1], p[i][1]);
		print(ans);
	}
	
}	

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
    
	return 0;
	
}
