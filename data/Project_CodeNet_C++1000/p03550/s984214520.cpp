#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, Z, W;
	cin >> N >> Z >> W;

	vector<long long> a(N);
	for (auto& x : a) {
		cin >> x;
	}

	if (N == 1) {
		cout << abs(a[0] - W) << endl;
	}
	else {
		auto ans = max(abs(a[N - 1] - W), abs(a[N - 2] - a[N - 1]));
		cout << ans << endl;
	}
}
