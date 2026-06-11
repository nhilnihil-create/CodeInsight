#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 2, K = 1e5 + 5;
int a[MAXN];
bool dp[K];
int n, k;

void input();
void solve();

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	input();
	solve();
	return 0;
}

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void solve() {
	for (int i = 1; i <= k; i++)
		for (int j = 0; j < n; j++)
			if (a[j] <= i && dp[i - a[j]] == false)
				dp[i] = true;
	dp[k]? cout << "First" << endl: cout << "Second" << endl;
}
