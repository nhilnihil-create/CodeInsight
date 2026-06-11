#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= 9; ++i) {
		if (i * 111 >= n) {
			ans = i * 111;
			break;
		}
	}  
	cout << ans;
}
