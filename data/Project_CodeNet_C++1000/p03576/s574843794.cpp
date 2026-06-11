#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, k;
	cin >> n >> k;
	vector<vector<int>> xy(n, vector<int>(2));
	vector<int> x(n);
	vector<int> y(n);
	vector<vector<int>> sum(n+1, vector<int>(n+1));
	rep(i, n){
		int ia, ib;
		cin >> ia >> ib;
		xy.at(i).at(0) = ia;
		xy.at(i).at(1) = ib;
		x.at(i) = ia;
		y.at(i) = ib;
	}
	x.push_back(-1000000001);
	y.push_back(-1000000001);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int zx = x.at(0);
	int zy = y.at(0);
	rep(i, n+1) rep(j, n+1){
		int co = 0;
		int ex = x.at(i);
		int ey = y.at(j);
		rep(l, n){
			if(xy.at(l).at(0) >= zx && xy.at(l).at(0) <= ex && xy.at(l).at(1) >= zy && xy.at(l).at(1) <= ey){
				co++;
			}
		}
		sum.at(i).at(j) = co;
	}
	ll mi = 4000000000000000001;
	for(int i=1; i<n; i++) for(int j=1; j<n; j++){
		for(int ii=i+1; ii<=n; ii++) for(int jj=j+1; jj<=n; jj++){
			int co = sum.at(ii).at(jj) - sum.at(ii).at(j-1) - sum.at(i-1).at(jj) + sum.at(i-1).at(j-1);
			if(co >= k){
				ll s = (ll)(x.at(ii) - x.at(i)) * (ll)(y.at(jj) - y.at(j));
				if(s < mi) mi = s;
			}
		}
	}
	cout << mi << endl;
	return 0;
}