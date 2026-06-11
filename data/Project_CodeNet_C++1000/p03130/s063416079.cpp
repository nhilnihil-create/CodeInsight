#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	vector<int> num(5, 0);
	for (int i = 0; i < 3; i++) {
		int a, b; cin >> a >> b;
		num[a]++;
		num[b]++;
	}
	string ans = "YES";
	for (int i = 1; i <= 4; i++) {
		if (num[i] == 0) ans = "NO";
		if (num[i] == 3) ans = "NO";
	}
	cout << ans << endl;
	return 0;
}