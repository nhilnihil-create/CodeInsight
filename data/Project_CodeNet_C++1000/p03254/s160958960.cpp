#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a.at(i);
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		x -= a.at(i);
		if (x < 0) {
			cout << i << endl;
			return 0;
		}
		else if (x == 0) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << n - 1 << endl;
}