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

	ll N,M;
	cin >> N >> M;
	map<ll,vector<ll>> m;
	vector<ll> P(M),Y(M); 
	rep(i,M){
		cin >> P[i] >> Y[i];
		m[P[i]].push_back(Y[i]);
	}

	map<ll,ll> juni;
	for(auto p:m){
		sort(p.second.begin(),p.second.end());
		rep(i,p.second.size()){
			juni[p.second[i]] = i;
			//cout << p.second[i] << endl;
		}
	}

	rep(i,M){
		printf("%06ld%06ld\n",P[i],juni[Y[i]]+1);
	}
	
	return 0;
}