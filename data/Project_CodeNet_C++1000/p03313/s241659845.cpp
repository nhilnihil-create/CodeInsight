#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, m, a[(1LL << 20)], dp[(1LL << 20)][20][2], ans[(1LL << 20)];

void setv(ll x, ll y, ll at){
	if(a[at] > a[dp[x][y][0]]){
		dp[x][y][1] = dp[x][y][0];
		dp[x][y][0] = at;
	}
	else{
		if(at != dp[x][y][0] && a[at] > a[dp[x][y][1]]){
			dp[x][y][1] = at;
		}
	}
}

void setp(ll x, ll y, ll u, ll v){
	setv(x, y, dp[u][v][0]);
	setv(x, y, dp[u][v][1]);
}

ll aa(ll x, ll y){
	return a[dp[x][y][0]]+a[dp[x][y][1]];
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	m = (1LL << n);
	zep(i, 0, m){cin >> a[i];}
	a[(1LL << 19)] = -INF;
	
	zep(i, 0, m){
		zep(j, 0, 20){
			dp[i][j][0] = (1LL << 19);
			dp[i][j][1] = (1LL << 19);
		}
	}
	zep(j, 0, 20){
		dp[0][j][0] = 0;
	}
	ans[0] = -INF;
	
	ll k;
	zep(bit, 1, m){
		if(__builtin_popcount(bit) == 1){k = bit;}
		
		setv(bit, 0, bit);
		zep(i, 0, 20){
			if(bit & (1LL << i)){
				setp(bit, 0, (bit & ~(1LL << i)), 0);
			}
		}

		zep(i, 1, 20){
			setv((bit & ~((1LL << i)-1)), i, bit);
		}
		
		zep(i, 1, 20){
			if(bit & (1LL << i)){
				ll buf = bit & ~((1LL << i+1)-1);
				zep(j, 0, 20){
					setp(buf, i, (buf & ~(1LL << j)), i);
				}
			}
		}
		
		ans[bit] = max(ans[k-1], aa(bit, 0));
		zep(i, 1, 20){
			if((bit & (1LL << i)) && ((1LL << i) != k)){
				ans[bit] = max(aa((bit & ~((1LL << i+1)-1)), i), ans[bit]);
			}
		}
		//cout << bit << ans[k-1] << dp[bit][0][0]+dp[bit][0][1] << endl;
	}
	
	zep(bit, 1, m){print(ans[bit])}
	//ll tmp; zep(bit, 1, m){cin >> tmp; if(ans[bit] != tmp){cout << bit << " " << ans[bit] << " " << tmp << endl;}}
	return 0;
}