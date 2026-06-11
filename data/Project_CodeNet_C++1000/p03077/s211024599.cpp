#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define INF 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<ll> t(5);		
	ll mint = INF;
	rep(i,5){
		cin >> t[i];
		mint = min(mint,t[i]);
	}
	
	ll ans = 4 + (ll)ceil((double)N / mint);

	cout << ans << endl;

	return 0;
}