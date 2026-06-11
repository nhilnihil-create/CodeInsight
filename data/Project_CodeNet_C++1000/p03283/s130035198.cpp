#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, m, q, a, b;
	cin >> n >> m >> q;
	vector<vector<int>> r(n, vector<int>(1));
	rep(i, n) r.at(i).at(0) = 1000;
	rep(i, m){
		cin >> a >> b;
		a--; b--;
		r.at(a).push_back(b);
	}
	rep(i, n) sort(r.at(i).begin(), r.at(i).end());
/*	cout << endl;
	rep(i, n){
		rep(j, r.at(i).size()) cout << r.at(i).at(j) << ' ';
		cout << endl;
	}*/
	rep(i, q){
		cin >> a >> b;
		a--; b--;
		int ans = 0;
		for(int j=a; j<=b; j++){
			ans += upper_bound(r.at(j).begin(), r.at(j).end(), b) - r.at(j).begin();
		}
		cout << ans << endl;
	}
	return 0;
}
