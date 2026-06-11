#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	string s;
	cin >> n;
	cin >> s;

	vector<long long> al(26,1);

	for (int i = 0; i < n; i++) {
		al[s[i] - 'a']++;
	}
	long long res = 1;
	for (int i = 0; i < 26; i ++ ) {
		res = (res*al[i]) % 1000000007;
	}
	cout << res - 1 << endl;

}