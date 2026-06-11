#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	string s, t; cin >> s >> t;
	map<char, char> m, n;
	for(int i=0;i<int(t.size());i++){
		if(m.find(t[i])==m.end()){
			m[t[i]] = s[i];
		}else{
			if(m[t[i]]!=s[i]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	for(int i=0;i<int(s.size());i++){
		if(n.find(s[i])==n.end()){
			n[s[i]] = t[i];
		}else{
			if(n[s[i]]!=t[i]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}