#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 7;

char s[N][N], t[N][N];
int n, res;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> s[i][j];
	for (int b = 0; b < n; b++) {
		for (int i = 1; i <= n - b; i++) 
			for (int j = 1; j <= n; j++)
				t[i][j] = s[i + b][j];
		for (int i = n - b + 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				t[i][j] = s[i - (n - b)][j];
		bool ok = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				ok &= (t[i][i - j + 1] == t[i - j + 1][i]);
			}
		}
		res += ok * n;
	}
	cout << res;

	return 0;
}
