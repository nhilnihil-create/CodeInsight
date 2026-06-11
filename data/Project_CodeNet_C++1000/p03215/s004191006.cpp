#include<bits/stdc++.h>
#include<boost/variant.hpp>
using namespace std;
typedef long long ll;
typedef vector<boost::variant<bool, ll, int, string, double, char*, const char*>> any;
template<typename T> inline void pr(const vector<T> &xs){
	for(int i=0; i<xs.size()-1; i++) cout<<xs[i]<<" ";
	(xs.empty()?cout:(cout<<xs[xs.size()-1]))<<endl;
}
#ifdef DEBUG
#define debug(...) pr(any{__VA_ARGS__})
#define debugv(x) pr((x))
#else
#define debug(...)
#define debugv(x)
#endif

int main(){
	int N, K;
	cin >> N >> K;
	vector<ll> A(N);
	for(int i=0; i<N; i++) cin >> A[i];

	vector<ll> sums;
	for(int i=0; i<N; i++){
		ll sum = 0;
		for(int j=i; j<N; j++){
			sum += A[j];
			sums.push_back(sum);
		}
	}

	ll ans = 0;
	for(int k=60; k>=0; k--){
		vector<ll> next;
		for(ll x: sums){
			if((x>>k)&1) next.push_back(x);
		}
		if(next.size()>=K){
			swap(sums, next);
			ans = ans | 1ll<<k;
		}
	}

	cout << ans << endl;

	return 0;
}
