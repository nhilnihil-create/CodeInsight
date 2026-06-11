#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using v2 = vector<vector<int>>;
int N;
int S=0;

void dfs(v2 a, int h, int w, int su){
	su += a.at(h).at(w);
	if(h == 1 && w == N-1){
		if(su > S) S = su;
	}
	v1 mh = {0, 1};
	v1 mw = {1, 0};
	for(int i = 0; i<2; i++){
		int nh = h + mh.at(i);
		int nw = w + mw.at(i);
		if(nh>=2 || nw>= N) continue;
		dfs(a, nh, nw, su);
	}
}

int main(){
	cin >> N;
	v2 a(2,vector<int>(N));
	rep(i, 2){
		for(int j = 0; j < N; ++j){
			cin >> a.at(i).at(j);
		}
	}
	dfs(a, 0, 0, 0);
	cout << S << endl;
}
