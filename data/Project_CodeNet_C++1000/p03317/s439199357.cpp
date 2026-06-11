#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i <= (ll)(n); ++i)
#define MAX 500010
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll INF = 1e10;
	
	ll N,K;
	cin >> N >> K;

	vector<ll> A(N);
	ll min_index,minn = INF;
	rep(i,N){
		cin >> A[i];
	}

	if(N==1){
		ans = 0;
	}
	else if(N - K <= 0){
		ans = 1;
	}
	else{
		N -= K;
		ans++;
		ans += (N + K - 2) /(K - 1);
	}

	cout << ans << endl;

	return 0;
}
