#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, Y;
	cin >> N >> Y;

	for (int x = 0; x <= N; ++x) {
		for (int y = 0; y <= N; ++y) {
			int z = N - (x + y);
			if (10000 * x + 5000 * y + 1000 * z == Y && x + y + z <= N && 0 <= z) {
				cout << x << ' ' << y << ' ' << z << endl;
				return 0;
			}
		}
	}
	cout << -1 << ' ' << -1 << ' ' << -1 << endl;
	return 0;
}