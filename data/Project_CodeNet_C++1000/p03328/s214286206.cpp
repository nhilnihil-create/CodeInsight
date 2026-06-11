#include"bits/stdc++.h"
using namespace std;

int sum(int n) {
	if (n == 1) {
		return 1;
	}
	int ans = sum(n - 1);
	ans += n;
	return ans;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << sum(b - a) - b << endl;
	return 0;
}