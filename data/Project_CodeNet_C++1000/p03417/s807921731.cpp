#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 100005;

int n;
int a[N];

int main() {

	FAST;

	int n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);
	if (n == 1 && m == 1) {
		cout << 1 << '\n';
	}
	else if (n == 1 && m != 1) {
		cout << m - 2 << '\n';
	}
	else {
		cout << 1LL * (n - 2) * (m - 2) << '\n';
	}
	return 0;
}