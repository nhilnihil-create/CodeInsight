#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

const int mod = 1e9+7;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> m;
	rep(i, n){
		char c = s[i];
		m[c]++;
	}
	ll ans = 1;
	for(auto p : m){
		ans = (ans * (p.second + 1)) % mod;
	}
	ans--;
	cout << ans << endl;
	return 0;
}