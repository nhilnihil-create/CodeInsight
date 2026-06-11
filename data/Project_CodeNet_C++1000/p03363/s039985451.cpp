#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N;
	cin >> N;
	ll A[N];
	for(int i = 0; i < N; i++) cin >> A[i];
	ll sum[N + 1];
	sum[0] = 0;
	for(int i = 0; i < N; i++) sum[i + 1] = sum[i] + A[i];
	sort(sum, sum + N + 1);
	ll ans = 0, cnt = 1;
	for(int i = 1; i < N + 1; i++) {
		if(sum[i - 1] == sum[i])
			cnt++;
		else {
			ans += cnt * (cnt - 1) / 2;
			cnt = 1;
		}
	}
	ans += cnt * (cnt - 1) / 2;
	cout << ans;
	return 0;
}
