#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define INF 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;
typedef pair<int, int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N,Q;
	cin >> N >> Q;

	string S;
	cin >> S;

	vector<int> d(N);
	d[0] = 0;
	rep(i,N-1){
		if(S[i] == 'A' && S[i+1] == 'C') d[i+1]++;
	}

	vector<int> imos(N);
	imos[0] = d[0];
	repk(i,1,N){
		imos[i] = imos[i-1] + d[i];
	}

	vector<int> l(Q),r(Q);
	rep(i,Q){
		cin >> l[i] >> r[i];
		l[i]--;
		r[i]--;
	}

	// rep(i,N){
	// 	cout << imos[i] << " ";
	// }
	// cout << endl;

	rep(i,Q){
		cout << imos[r[i]] - imos[l[i]] << endl;
	}

	return 0;
}