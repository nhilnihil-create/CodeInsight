#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > b[i]) {
			sum += a[i] - b[i];
		}
	} 
	cout << sum;
}

















