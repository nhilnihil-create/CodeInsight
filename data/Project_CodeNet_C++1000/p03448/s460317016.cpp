#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int a, b, c;
int x;
int solver() {
	int ans = 0;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= c; k++) {
				int tmp = i * 500 + j * 100 + k * 50;
				if (tmp == x)ans++;
			}
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> a >> b >> c >> x;
	int ans = solver();

	cout << ans << endl;
}