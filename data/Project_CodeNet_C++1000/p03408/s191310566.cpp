#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	map<string,int> cnt;
	rep(i,n){
		string s;
		cin >> s;
		cnt[s]++;
	}
	int m;
	cin >> m;
	rep(i,m){
		string t;
		cin >> t;
		cnt[t]--;
	}
	int maxim = 0;
	for(auto p : cnt){
		auto k = p.first;
		auto v = p.second;
		maxim = max(maxim,v);
	}
	cout << maxim << endl;
}