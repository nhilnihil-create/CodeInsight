#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> g;
vector<int> it;
int k = 0;

int f(int x){
	it.at(x) = k;
	rep(i, g.at(x).size()){
		if(it.at(g.at(x).at(i)) != -1) continue;
		f(g.at(x).at(i));
	}
	return 0;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	g = vector<vector<int>>(n, vector<int>(0));
	it = vector<int>(n);
	rep(i, n){
		cin >> p.at(i);
		it.at(i) = -1;
	}
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g.at(a).push_back(b);
		g.at(b).push_back(a);
	}
	rep(i, n){
		if(it.at(i) == -1){
			f(i);
			k++;
		}
	}
	int ans = 0;
	rep(i, n){
		if(it.at(p.at(i)-1) == it.at(i)) ans++;
	}
	cout << ans << endl;
	return 0;
}