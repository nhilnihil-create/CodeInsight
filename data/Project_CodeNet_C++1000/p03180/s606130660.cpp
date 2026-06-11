#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;

#define rep(i,n)	for(ll i=0;i<(n);i++)
#define SZ(x) ((ll)x.size())
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define F first
#define S second
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// const ll MOD = INT_MAX;
const double PI = acos(-1);

void openfile(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
}

const ll INF = 1e18 + 7;
vector<ll> pre;
// pre[mask] - score of group 'mask'
vector<ll> dp;

void rec(int i, const vector<int>& not_taken, ll cur_score, int mask, int group){
	if(i == SZ(not_taken)){
		dp[mask] = max(dp[mask], cur_score + pre[group]);
		return;
	}
	rec(i + 1, not_taken, cur_score, mask, group);
	rec(i + 1, not_taken, cur_score, mask ^ (1 << not_taken[i]), group ^ (1 << not_taken[i]));

}

// O(2^n * n^2 * 3^n)
signed main(){
	IOS
	int n;
	scanf("%d", &n);

	vector<vector<ll>> in(n,vector<ll>(n));
	rep(i,n){
		rep(j,n)	scanf("%lld", &in[i][j]);
	}

	// O(2^n * n^2)
	pre.resize(1 << n);
	for(int mask = 0; mask < (1 << n); mask++){
		for(int i = 0; i < n; i++){
			if(mask & (1 << i)){
				for(int j = i+1; j < n; j++){
					if(mask & (1 << j)){
						pre[mask] += in[i][j];
					}
				}
			}
		}
	}
	// dp[mask] - best total score if we grouped the rabbits from 'mask' already
	dp.resize(1 << n, -INF);
	dp[0] = 0;
	for(int mask = 0; mask < (1 << n); mask++){
		vector<int> not_taken;
		for(int i = 0; i < n; i++){
			if(!(mask & (1 << i))){
				not_taken.pb(i);
			}

		}
		rec(0, not_taken, dp[mask], mask, 0);
	}
	printf("%lld\n", dp[(1 << n) - 1]);


}
