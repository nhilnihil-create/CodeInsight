#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define inf 1e9
typedef pair<int,int> pii;
typedef pair <long long,long long> pll;
typedef long long ll; 
typedef long double ld; 
const ll mod = 1e9+7;
struct flower{
	ll hi; ll bty;
};
ll solve(vector< flower > &v, int n )
{	vector <ll> dp(n+1);
	map <ll,ll> meaningful;
	dp[1] = v[1].bty;
	meaningful[v[1].hi] = dp[1];
	ll ans = dp[1];
	for(ll i = 2; i<=n ; i++)
	{
		dp[i] = v[i].bty;
		auto it = meaningful.lower_bound(v[i].hi + 1);
		if(it != meaningful.begin()){
			it--;
			dp[i] += it->se;
		}
		meaningful[v[i].hi] = dp[i];
		it = meaningful.upper_bound(v[i].hi);
		while(it != meaningful.end() && it->se <= dp[i] ){
			auto tmp = it;
			tmp++;
			meaningful.erase(it);
			it = tmp;
		}
		ans = max(ans,dp[i]);
	}
    return ans;
} 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n; cin >> n;
	vector < flower > v(n+1);
	for(ll i = 1; i <= n; i++)
		cin >> v[i].hi;
	for(ll i = 1; i<= n; i++)
		cin >> v[i].bty;
	cout << solve( v , n );
	return 0;
}
