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

void solve(){
	
	ll N;
	cin >> N;
	vl A(N);
	rep(i, N) cin >> A[i];
	
	vl acc(N + 5);
	rep(i, N) acc[i + 1] = acc[i] + A[i];
	ll ans = 0;
	map<ll, ll> mp;
	rep(i, N + 1){
		ans += mp[acc[i]];
		mp[acc[i]] += 1;
	}
	
	print(ans);

}	

int main(){
    
    fastio;
	solve();
    
	return 0;
	
}
