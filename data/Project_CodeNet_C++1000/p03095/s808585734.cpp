#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n-1); i >= 0; i--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define repitr(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> m;
	rep(i, n){
		m[s[i]]++;
	}
	ll ans = 1;
	for(auto p : m){
		p.second++;
		ans *= p.second;
		ans %= 1000000007;
	}
	ans = (ans - 1) % 1000000007;
	cout << ans << endl;
	return 0;
}