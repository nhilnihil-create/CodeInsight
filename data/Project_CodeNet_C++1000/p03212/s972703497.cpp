
// C - 755

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N;
int ans = 0;

bool is_753(ll k) {
	bool has7 = false, has5 = false, has3 = false;
	while(k > 0) {
		if (k % 10 == 7) has7 = true;
		if (k % 10 == 5) has5 = true;
		if (k % 10 == 3) has3 = true;

		k /= 10;
	}

	return has7 && has5 && has3;
}

void dfs(ll k) {
	if (k > N) return;
	if (is_753(k)) ans++;

	dfs(k*10 + 7);
	dfs(k*10 + 5);
	dfs(k*10 + 3);
}

int main() {
	cin >> N;

	dfs(0);

	cout << ans << endl;

	return 0;
}