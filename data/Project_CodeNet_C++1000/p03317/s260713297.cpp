#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k; cin >> n >> k;
	int a[n];
	int one;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << (n - 1 + k - 2) / (k - 1) << endl;
	return 0;
}
