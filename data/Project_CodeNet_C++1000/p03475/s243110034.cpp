#include <bits/stdc++.h>

using namespace std;
const int N = 501;
int c[N], s[N], f[N];

int calculate(int t, int i, int n) {
	if (i == n - 1) { 
		return t;
	} else {
		if (t < s[i]) t = s[i];
		if (t % f[i] != 0) t += f[i] - (t % f[i]);
		return calculate(t + c[i], i + 1, n);
	}
}

int main() {
	
	int n; cin >> n;
	
	for (int i = 0; i < n-1; i++) cin >> c[i] >> s[i] >> f[i];
	for (int i = 0; i < n; i++) cout << calculate(0, i, n) << endl;
	return 0;
}