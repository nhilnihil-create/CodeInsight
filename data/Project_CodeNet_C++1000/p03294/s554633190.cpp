#include<bits/stdc++.h>
using namespace std;

int f(int m, int a) {
	return m % a;
}

int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res += a[i] - 1;
	}
	cout << res << endl;

	return 0;
}
