#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main(int argc, char** argv) {
	long long N, Z, W;

	cin >> N >> Z >> W;

	vector<long long> a(N);

	REP(i, N) cin >> a[i];

	if (N == 1) {
		cout << abs(W - a[0]) << endl;
	}
	else {
		cout << max(abs(W - a[N - 1]), abs(a[N - 1] - a[N - 2])) << endl;
	}
}
