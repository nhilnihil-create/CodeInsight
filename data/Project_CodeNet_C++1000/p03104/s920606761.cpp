#include <bits/stdc++.h>
#define INF 100000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = inx(x, y)
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
using vvs = vector<vector<string>>;

ll f(ll x){

	if(x % 4 == 0) return 0 ^ x;
	if(x % 4 == 1) return 1;
	if(x % 4 == 2) return 1 ^ x;
	if(x % 4 == 3) return 0;
	
}		

void solve(){
	
	ll A, B;
	cin >> A >> B;
	ll ans = f(B) ^ f(A - 1);
	print(ans);
		
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
    
	return 0;
	
}



