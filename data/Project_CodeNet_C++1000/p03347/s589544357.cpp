#include<iostream>

using namespace std;

int a[200010];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (a[0] != 0) {
		cout << -1 << endl;
		return 0;
	}
	long long an = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] == 1) {
			an++;
		}
		else if (a[i] - a[i - 1] < 1) {
			an += a[i];
		}
		else if (a[i] - a[i - 1] > 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << an << endl;
}