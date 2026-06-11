#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int f(int l){
	int res = 0, cur = 1;
	while(l >= cur){
		++res;
		cur <<= 1;
	}
	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int l;
	cin >> l;
	int n = f(l);
	vector<vector<P>> g(n);
	int m = 2 * (n-1);
	rep(i,n-1){
		g[i].emplace_back(i+1, 0);
		g[i].emplace_back(i+1, (1<<i));
	}
	int cur = (1<<(n-1));
	for(int i = n-2; i >= 0; --i){
		if(cur >= l) break;
		int hoge = (1<<i);
		if(cur + hoge > l) continue;
		g[i].emplace_back(n-1, cur);
		++m;
		cur += hoge;
		if(cur >= l) break;
	}
	cout << n << " " << m << endl;
	rep(i,n){
		for(auto p : g[i]){
			cout << i+1 << " " << p.first + 1 << " " << p.second << endl;
		}
	}
	return 0;
}
