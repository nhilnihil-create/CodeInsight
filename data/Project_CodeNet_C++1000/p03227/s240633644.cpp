#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;
#define ll long long
#define ar array

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	
	if (S.size()==2) {
		cout << S << endl;
	} else {
		cout << S.at(2) << S.at(1) << S.at(0) << endl;
	}
	return 0;
}
