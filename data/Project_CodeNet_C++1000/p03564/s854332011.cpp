#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	int p = 1;
	for (int i = 0; i < n; ++i) {
		if (p * 2 < p + k) {
			p = p * 2;
		}else {
			p = p +  k;
		}
	}
	cout << p;
}
