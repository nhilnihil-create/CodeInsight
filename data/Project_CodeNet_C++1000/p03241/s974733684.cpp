#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1010101010

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a;
	for (int i = 1; i * i <= m; i++) {
		if (m % i == 0) {
			a.emplace_back(i);
			a.emplace_back(m / i);
		}
	}

	int mx = 1;
	for (auto& i : a) {
		if (i >= n) {
			mx = max(mx, m / i);
		}
	}
	cout << mx << endl;

	return 0;
}