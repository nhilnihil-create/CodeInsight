#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, d, x; cin >> n >> d >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		a.at(i) = d / m;
		if (d % m != 0) a.at(i)++;
	}
	int m = 0;
	for (int i = 0; i < n; i++) {
		m += a.at(i);
	}
	cout << m + x << endl;
}