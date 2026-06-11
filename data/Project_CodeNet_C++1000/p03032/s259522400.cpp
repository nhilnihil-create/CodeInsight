#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N, K;
	cin >> N >> K;

	vector<ll> V(N);
	rep(i, N) cin >> V[i];


	ll ans = 0;
	for(ll l = 0; l <= min(K, N); l++) {
		for(ll r = 0; r <= min(K - l, N - l); r++) {
			ll rest = K - l - r;

			vector<ll> vec;	
			for(ll i = 0; i < l; i++) vec.push_back(V[i]);
			for(ll i = 0; i < r; i++) vec.push_back(V[N-1-i]);

			sort(vec.begin(), vec.end());

			ll sum = 0;
			for(ll i = 0; i < vec.size(); i++) {
				if(i < rest && vec[i] < 0) continue;
				sum += vec[i];
			}
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;

}
