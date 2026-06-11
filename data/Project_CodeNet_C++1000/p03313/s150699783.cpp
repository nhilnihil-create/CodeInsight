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

ll n, m, a[(1LL << 20)], dp[(1LL << 20)][2], ans[(1LL << 20)];

void setv(ll x, ll at){
	if(a[at] > a[dp[x][0]]){
		dp[x][1] = dp[x][0];
		dp[x][0] = at;
	}
	else{
		if(at != dp[x][0] && a[at] > a[dp[x][1]]){
			dp[x][1] = at;
		}
	}
}

void setp(ll x, ll u){
	setv(x, dp[u][0]);
	setv(x, dp[u][1]);
}

ll aa(ll x){
	return a[dp[x][0]]+a[dp[x][1]];
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	m = (1LL << n);
	zep(i, 0, m){cin >> a[i];}
	a[m] = -INF;
	zep(i, 0, m){
		dp[i][0] = i;
		dp[i][1] = m;
	}
	ans[0] = -INF;
	
	zep(i, 0, m){
		zep(j, 0, 20){
			if(i & (1LL << j)){
				setp(i, (i & ~(1LL << j)));
			}
		}
	}
	
	zep(i, 1, m){
		ans[i] = max(ans[i-1], aa(i));
		print(ans[i])
	}
	return 0;
}