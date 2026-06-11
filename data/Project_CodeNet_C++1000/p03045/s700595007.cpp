#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> g;
vector<vector<int>> gw;
vector<int> gc;

int f(int x, int c, int o = -1){
	gc.at(x) = c;
	rep(i, g.at(x).size()){
		if(gc.at(g.at(x).at(i)) != -1) continue;
			f(g.at(x).at(i), c, x);
	}
	return 0;
}

int main(){
	int n, m;
	cin >> n >> m;
	g = vector<vector<int>>(n, vector<int>(0));
	gw = vector<vector<int>>(n, vector<int>(0));
	gc = vector<int>(n);
	rep(i, m){
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		g.at(a).push_back(b);
		g.at(b).push_back(a);
		gw.at(a).push_back(w%2);
		gw.at(b).push_back(w%2);
	}
	rep(i, n) gc.at(i) = -1;
	int k = 0;
	rep(i, n){
		if(gc.at(i) == -1){
			f(i, k);
			k++;
		}
	}
	cout << k << endl;
	return 0;
}