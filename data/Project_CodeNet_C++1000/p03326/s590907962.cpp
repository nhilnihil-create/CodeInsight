#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> a(8, vector<ll>(n));
	rep(i, n){
		ll ai, bi, ci;
		cin >> ai >> bi >> ci;
		a.at(0).at(i) = +ai+bi+ci;
		a.at(1).at(i) = +ai+bi-ci;
		a.at(2).at(i) = +ai-bi+ci;
		a.at(3).at(i) = +ai-bi-ci;
		a.at(4).at(i) = -ai+bi+ci;
		a.at(5).at(i) = -ai+bi-ci;
		a.at(6).at(i) = -ai-bi+ci;
		a.at(7).at(i) = -ai-bi-ci;
	}
	rep(i, 8){
		sort(a.at(i).begin(), a.at(i).end());
		reverse(a.at(i).begin(), a.at(i).end());
	}
	vector<ll> sum(8);
	rep(i, 8) sum.at(i) = 0;
	rep(i, 8) rep(j, m) sum.at(i) += a.at(i).at(j);
	ll ans = -100000000000000;
	rep(i, 8) ans = max(ans, sum.at(i));
	cout << ans << endl;
	return 0;
}