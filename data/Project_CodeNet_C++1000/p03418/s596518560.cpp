#include <bits/stdc++.h>
#define INF 100000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << " " << y << "\n"
#define printv(vec) rep(i, vec.size()) cout << vec[i] << " "; print("");
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

void Main(){
	
	ll N, K;
	cin >> N >> K;
	ll ans = 0;
	rep2(b, 1, N + 1){
		ll cnt = b - K;
		if(cnt > 0){
			ll div = (N + 1) / b;
			ll mod = N + 1 - div * b;
			ans += div * cnt + max(mod - K, (ll)0);
		}
	}
	if(K == 0) ans -= N;
	print(ans);
		
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Main();
    
	return 0;
	
}



