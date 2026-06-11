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
	int N;
	cin >> N;
	string S;
	cin >> S;
	int Q;
	cin >> Q;
	vector<int> K(Q);
	for(int i=0; i<Q; i++) cin >> K[i];

	for(int k: K){
		ll ans = 0;
		ll n_d=0, n_m=0, n_dm=0;
		for(int i=0; i<k; i++){
			if(S[i]=='D') n_d++;
			if(S[i]=='M'){
				n_dm += n_d;
				n_m++;
			}
			if(S[i]=='C') ans += n_dm;
		}
		for(int i=k; i<N; i++){
			if(S[i-k]=='D'){
				n_d--;
				n_dm -= n_m;
			}
			if(S[i-k]=='M') n_m--;
			if(S[i]=='D') n_d++;
			if(S[i]=='M'){
				n_dm += n_d;
				n_m++;
			}
			if(S[i]=='C') ans += n_dm;
		}
		cout << ans << endl;
	}

	return 0;
}
