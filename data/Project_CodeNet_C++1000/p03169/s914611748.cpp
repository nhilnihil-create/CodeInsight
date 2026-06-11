#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 305;
int n;
ld dp[N][N][N];
bool mark[N][N][N];

ld solve(int f1, int f2, int f3){
	if(f1 == 0 && f2 == 0 && f3 == 0)
		return 0;
	ld &ans = dp[f1][f2][f3];
	if(mark[f1][f2][f3])
		return ans;
	ans = 1;
	mark[f1][f2][f3] = 1;
	if(f1)
		ans += ((ld)f1 / n) * solve(f1 - 1, f2, f3);
	if(f2)
		ans += ((ld)f2 / n) * solve(f1 + 1, f2 - 1, f3);
	if(f3)
		ans += ((ld)f3 / n) * solve(f1, f2 + 1, f3 - 1);
	ans /= (1 - (ld)(n - f1 - f2 - f3) / n);
	return ans;
}

int main() {
	cin >> n;
	int f[4] = {};
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		f[a]++;
	}
	cout << fixed << setprecision(12) << solve(f[1], f[2], f[3]);
	return 0;
}

