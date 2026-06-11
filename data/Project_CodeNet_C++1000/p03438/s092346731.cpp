#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long> a(N), b(N);
	for (long& i : a) cin >> i;
	for (long& i : b) cin >> i;
	pair<long, long> c;
	for (int i = 0; i < N; i++) {
		if (a[i] < b[i]) {
			c.first += (b[i] - a[i] + 1) / 2;
			c.second += (b[i] - a[i]) % 2;
		}
		else if (b[i] < a[i]) c.second += a[i] - b[i];
	}
	if (c.first < c.second) cout << "No";
	else cout << "Yes";
}