#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int a[N];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	long long cur = 1, now = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cur *= 3;
		if (a[i] % 2 == 0) now *= 2;
	}
	cout << cur - now << "\n";
	
	return 0;
}
