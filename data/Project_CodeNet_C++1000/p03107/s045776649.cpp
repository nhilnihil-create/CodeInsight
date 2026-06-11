#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	int oneCnt = 0;
	int zeroCnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') zeroCnt++;
		else oneCnt++;
	}
	
	cout << 2 * min(zeroCnt, oneCnt) << endl;
	return 0;
}