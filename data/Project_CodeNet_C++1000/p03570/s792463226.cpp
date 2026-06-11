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

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	ll n = s.size();
	map<ll, ll> mp;
	
	vector<P> v;
	ll bit = 0;
	mp[0] = bit;
	zep(i, 0, n){
		ll c = s[i]-'a';
		bit ^= (1LL << c);
		
		if(mp.find(bit) != mp.end()){
			v.push_back(P(mp[bit], i+1));
		}
		zep(j, 0, 26){
			if(mp.find(bit ^ (1LL << j)) != mp.end()){
				v.push_back(P(mp[bit ^ (1LL << j)], i+1));
			}
		}
		mp[bit] = i+1;
	}
	
	ll dp[2][n+1];
	rep(i, 0, n){
		dp[0][i] = INF;
		dp[1][i] = INF;
	}
	dp[0][0] = 0;
	
	zep(i, 0, v.size()){
		ll l = v[i].first;
		ll r = v[i].second;
		if((r-l)%2 == 0){
			dp[0][r] = min(dp[0][l], dp[0][r]);
			dp[1][r] = min(dp[1][l], dp[1][r]);
		}
		else{
			dp[1][r] = min(min(dp[0][l]+1, dp[1][l]+1), dp[1][r]);
		}
	}
	print(max(min(dp[0][n], dp[1][n]), 1LL))
	//zep(i, 0, v.size()){cout << v[i].first << v[i].second << endl;}
	return 0;
}