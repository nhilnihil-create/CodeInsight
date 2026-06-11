#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	int n = s.size();
	bool ans = false;
	rep(i, n){
		rep(j, n){
			if(j < i) continue;
			if(s.substr(0, i)+s.substr(j) == "keyence") ans = true;
		}
	}
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
