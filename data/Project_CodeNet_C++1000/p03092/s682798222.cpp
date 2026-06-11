#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
long long n, a, b, x[N];
long long f[N][N], pos[N], p[N][N];

main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> a >> b;
	for(int i = 1; i <= n; ++i) cin >> x[i];
	memset(f, 127, sizeof(f));
	long long oo = f[0][0];
	f[0][0] = 0;
	for(int i = 1; i <= n; ++i) {
		pos[x[i]] = i;
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= n; ++j) {
			if(j < x[i + 1]) {
				f[i+1][j] = min(f[i+1][j], f[i][j] + a);
				f[i+1][x[i+1]] = min(f[i+1][x[i+1]], f[i][j]);
			}
			else{
				f[i+1][j] = min(f[i+1][j], f[i][j] + b);
			}
		}
	}
	for(int i = 0; i <= n; ++i) oo = min(oo, f[n][i]);
	cout << oo << '\n'; 
}