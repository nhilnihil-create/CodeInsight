#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using namespace std;

const int N = 2032;
int n, a[N];
bitset<N * N / 2 + N> kn;

int main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	kn.set(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		kn |= kn << a[i];
	}
	cout << kn._Find_next((accumulate(a, a + n, 0) - 1) / 2) << "\n";
	return 0;
}

