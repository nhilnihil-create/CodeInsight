#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	map<string,int> mp;
	int n,m;
	cin >> n;
	rep(i,n){
		string s;
		cin >> s;
		mp[s]++;
	}
	cin >> m;
	rep(i,m){
		string s;
		cin >> s;
		mp[s]--;
	}
	int nax = -INF;
	for(auto it:mp){
		if(nax<it.second)
			nax = it.second;	
	}	
	cout << max(nax,0) << endl;
	return 0;
}

