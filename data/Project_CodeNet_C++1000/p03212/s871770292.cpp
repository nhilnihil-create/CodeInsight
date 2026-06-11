#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll n, ret;

void dfs(ll num, int three, int five, int seven) {
	if (num > n) return ;
	if (three * five * seven > 0) ret++;

	dfs(10 * num + 3, 1, five, seven);
	dfs(10 * num + 5, three, 1, seven);
	dfs(10 * num + 7, three, five, 1);
	return ;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;

	dfs(0, 0, 0, 0);

	cout << ret << '\n';
	return 0;
}
