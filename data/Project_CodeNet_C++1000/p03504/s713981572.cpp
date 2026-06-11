#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5+1;

const ll MAX = (1LL<<62);

int s[N], t[N], c[N];
int all[2*N], temp[2*N];

int main () {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, C, T = 0; cin >> n >> C; 
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> t[i] >> c[i];
		T = max(T, t[i]);
	}

	for (int color = 1; color <= C; color++) {
		for (int i = 0; i < 2*T; i++)
			temp[i] = 0;
		for (int i = 0; i < n; i++)
			if (c[i] == color) {
				temp[2*s[i]-1]++;
				temp[2*t[i]]--;
			}
		for (int i = 1; i < 2*T; i++)
			temp[i] += temp[i-1];
		// put into actual
		for (int i = 0; i < 2*T; i++)
			all[i] += (temp[i] > 0);
	}

	int ans = 0;
	for (int i = 0; i < 2*T; i++)
		ans = max(ans, all[i]);
	cout << ans << endl;
	return 0;
}