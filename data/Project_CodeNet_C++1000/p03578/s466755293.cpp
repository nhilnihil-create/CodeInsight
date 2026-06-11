#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, m;

int main(void){
	cin >> n;
	unordered_map<string, lli> d(n);
	rep(i, n){
		string a;
		cin >> a;
		d[a]++;
	}
	cin >> m;
	unordered_map<string, lli> t(m);
	rep(i, m){
		string a;
		cin >> a;
		t[a]++;
	}
	bool f = true;
	for(auto i : t){
		if(i.second > d[i.first]) f = false;
	}
	if(f) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
