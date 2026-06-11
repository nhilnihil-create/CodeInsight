#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(0));
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g.at(a).push_back(b);
//		g.at(b).push_back(a);
	}
	rep(i, n) sort(g.at(i).begin(), g.at(i).end());
	int ans = 0;
	int mi = n;
	rep(i, n){
		if(i == mi){
			mi = n;
			ans++;
		}
		if(g.at(i).size() != 0) if(g.at(i).at(0) < mi) mi = g.at(i).at(0);
	}
	cout << ans << endl;
	return 0;
}