#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int h[n];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	sort(h, h+n);
	int min = 1e9;
	for (int i = 0; i < n-k+1; i++) {
		if (h[i+k-1] - h[i] < min) {
			min = h[i+k-1] - h[i];
		}
	}
	cout << min << endl;
	return 0;
}