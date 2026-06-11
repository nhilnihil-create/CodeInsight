#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

ll a[225816],dp[225816];
map<ll, ll> mp;

int main(void){
	int n,i,j;
	string s;
	fill(dp,dp+225816,INFLL);
	cin >> s;
	n = s.l_ength();
	for(i=0; i<n; ++i){
		a[i] = (1ll<<(s[i]-'a'));
	}
	for(i=1; i<n; ++i){
		a[i] ^= a[i-1];
	}
	for(i=0; i<n; ++i){
		mp[a[i]] = INFLL;
	}
	mp[0] = 0ll;
	for(i=0; i<n; ++i){
		if(mp.count(a[i])){
			dp[i] = min(mp[a[i]]+1,dp[i]);
		}
		for(j=0; j<26; ++j){
			if(mp.count(a[i]^(1ll<<j))){
				dp[i] = min(mp[a[i]^(1ll<<j)]+1,dp[i]);
			}
		}
		mp[a[i]] = min(mp[a[i]],dp[i]);
	}
	cout << dp[n-1] << endl;
	return 0;
}
