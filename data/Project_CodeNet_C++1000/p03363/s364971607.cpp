#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long> Subsum(N);
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		Subsum[i] = A + (i > 0 ? Subsum[i - 1] : 0);
	}
	sort(Subsum.begin(), Subsum.end());
	long long ans = 0;
	for (auto itr = Subsum.begin(); itr != Subsum.end(); itr++) {
		if (*itr == 0) ans++;
		ans += distance(lower_bound(itr + 1, Subsum.end(), *itr),
			upper_bound(itr + 1, Subsum.end(), *itr));
	}
	cout << ans << endl;
}
