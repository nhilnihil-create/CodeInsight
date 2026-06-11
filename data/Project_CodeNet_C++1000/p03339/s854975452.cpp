#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	string s; cin >> s;

	vector<int> e_num(n, 0), w_num(n, 0);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'E') e_num[i]++;
		else w_num[i]++;		
		if (i == 0) continue;
		e_num[i] += e_num[i - 1];
		w_num[i] += w_num[i - 1];
	}

	int ans = 2147483647;;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		tmp += e_num[n - 1] - e_num[i];
		tmp += w_num[i - 1];
		ans = min(ans, tmp);
	}

	cout << ans << endl;
	return 0;
}