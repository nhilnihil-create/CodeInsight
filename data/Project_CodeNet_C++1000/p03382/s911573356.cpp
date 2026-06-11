#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	auto it = upper_bound(arr.begin(), arr.end(), arr.back() / 2);
	int ans;
	ans = *it;

	if (it != arr.begin()) {
		it--;
		if (*it >= arr.back() - ans) ans = *it;
	}

	cout << arr.back() << ' ' << ans;
}