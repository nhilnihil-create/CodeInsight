#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 100005;

int n;
int a[N];

int main() {

	FAST;

	char x;
	string ans = "";
	for (int i = 0; i < 9; i ++) {
		cin >> x;
		if (i == 0) {
			ans += x;
		}
		if (i == 4) {
			ans += x;
		}
		if (i == 8) {
			ans += x;
		}
	}
	cout << ans << '\n';
	return 0;
}