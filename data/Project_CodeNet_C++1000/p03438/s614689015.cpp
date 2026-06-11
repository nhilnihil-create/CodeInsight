#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

signed main()
{
	int N; cin >> N;
	vector<int> a(N), b(N);

	long long sa = 0, sb = 0;

	for (int i = 0; i < N; ++i) cin >> a[i], sa += a[i];
	for (int i = 0; i < N; ++i) cin >> b[i], sb += b[i];

	if (sb - sa < 0) {
		cout << "No" << endl;
		return 0;
	}

	long long sousa = sb - sa, counter = 0;
	
	for (int i = 0; i < N; ++i) {
		if (a[i] < b[i]) {
			counter += (b[i] - a[i] + 1) / 2;
		}
	}

	if (counter <= sousa) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
