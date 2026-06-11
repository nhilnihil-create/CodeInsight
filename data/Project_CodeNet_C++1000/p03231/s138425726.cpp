#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, m;
string s, t;

lli gcd(lli a, lli b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void){
	cin >> n >> m >> s >> t;
	lli l = n*m/gcd(n, m);
	bool ans = true;
	unordered_map<lli, char> mp;
	for(int i = 0; i < n; i++){
		mp[l/n*i] = s[i];
	}
	for(int i = 0; i < m; i++){
		if(mp.count(l/m*i) > 0 && mp[l/m*i] != t[i]) ans = false;
	}
	if(ans) cout << l << endl;
	else cout << -1 << endl;
	return 0;
}
