#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> g;
vector<int> id;
vector<ll> sum;

int f(int x, int ida){
	id.at(x) = ida;
	rep(i, g.at(x).size()){
		if(id.at(g.at(x).at(i)) != ida) f(g.at(x).at(i), ida);
	}
	return 0;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> ce(m, vector<int>(2));
	rep(i, m) cin >> ce.at(i).at(0) >> ce.at(i).at(1);
	g = vector<vector<int>>(n, vector<int>(0));
	id = vector<int>(n);
	sum = vector<ll>(n);
	vector<ll> a(m);
	ll ans = (ll)n*((ll)n-1)/2;
	rep(i, n){
		id.at(i) = i;
		sum.at(i) = 1;
	}
	for(int i=m-1; i>0; i--){
		int c0 = ce.at(i).at(0) -1;
		int c1 = ce.at(i).at(1) -1;
		a.at(i) = ans;
		if(id.at(c0) != id.at(c1)){
			ans -= sum.at(id.at(c0)) * sum.at(id.at(c1));
			if(sum.at(id.at(c0)) < sum.at(id.at(c1))){
				sum.at(id.at(c1)) = sum.at(id.at(c0)) + sum.at(id.at(c1));
				f(c0, id.at(c1));
			}else{
				sum.at(id.at(c0)) = sum.at(id.at(c0)) + sum.at(id.at(c1));
				f(c1, id.at(c0));
			}
			g.at(c0).push_back(c1);
			g.at(c1).push_back(c0);
		}
	}
	a.at(0) = ans;
	rep(i, m) cout << a.at(i) << endl;
	return 0;
}