#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void RET () {
	cout << -1;
	exit (0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector <int> a(n+1), ans;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int q=1; q<=n; q++) {
		bool find = 0;
		for (int i=n-q+1; i>=1; i--) {
			if (a[i] == i) {
				find = 1;
				a.erase(a.begin()+i);
				ans.push_back(i);
				break;
			}
		}
		if (!find) RET();
	}
	reverse (ans.begin(), ans.end());
	for (auto i:ans) {
		cout << i << "\n";
	}
	return 0;
}
