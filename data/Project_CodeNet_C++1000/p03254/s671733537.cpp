#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, x;
	cin >> N >> x;
	int a[100];
	for (int i = 0; i < N; ++i) cin >> a[i];
	sort(a, a + N);
	int res = 0;
	for (int i = 0; i < N; ++i) {
		if (a[i] <= x) {
			if (i + 1 == N && x > a[i]) break;
			x -= a[i];
			++res;
		}
		else break;
	}

	cout << res << endl;
}