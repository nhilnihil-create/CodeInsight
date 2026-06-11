#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const ll N = 5e3 + 15, inf = 1000000LL * 1000000LL * 10, LOG = 23;
ll n, R, L;
int Arr[N];
ll dp[N], ans;
vector <int> vec;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> R >> L;
	for (int i = 0; i < n; i++)
		cin >> Arr[i];

	for (int i = 0; i < n; i++) {
		while (vec.size() && Arr[vec.back()] > Arr[i])
			vec.pop_back();

		dp[i] = inf;
		if (vec.empty())
			dp[i] = R * i;

		int cnt = 0, val = 0;
		for (int j = i - 1; ~j; j--) {
			if (Arr[j] < Arr[i])
				val = max(val, Arr[j]);

			if (Arr[j] < Arr[i] && val == Arr[j])
				dp[i] = min(dp[i], dp[j] + L * (i - j - 1 - cnt) + R * cnt);

			cnt += (Arr[j] > Arr[i]);
		}

		vec.push_back(i);
	}

	vec.clear();

	ans = inf;
	for (int i = n - 1; ~i; i--) {
		while (vec.size() && Arr[vec.back()] < Arr[i])
			vec.pop_back();

		if (vec.empty())
			ans = min(ans, dp[i] + (n - i - 1) * L);

		vec.push_back(i);
	}

	cout << ans << "\n";
	return 0;
}