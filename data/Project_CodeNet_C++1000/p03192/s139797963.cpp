#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;
#define ll long long
#define ar array

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string N;
	cin >> N;
	int ans = 0;

	for (int i = 0; i < N.size(); i++) {
		if (N.at(i)=='2') ans++;
	}
	cout << ans << endl;
	return 0;
}
