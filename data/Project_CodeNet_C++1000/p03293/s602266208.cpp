#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;
#define ll long long
#define ar array

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S,T;
	cin >> S >> T;
	bool ans = false;
	for (int i = 0; i < S.size(); i++) {
		if(S==T) {
			ans=true;
			break;
		}
		S=S.back()+S.substr(0,S.size()-1);
	}
	if (ans) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
