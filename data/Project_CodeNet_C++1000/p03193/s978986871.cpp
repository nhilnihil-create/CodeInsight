#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, h, w;
	cin >> n >> h >> w;
	vector<int>a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i) >> b.at(i);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a.at(i) >= h && b.at(i) >= w) ans++;
	}

	cout << ans << endl;
}