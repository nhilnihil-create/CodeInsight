#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N, x;
	cin >> N >> x;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	int ans = 0;
	for(int i = 0; i < N; i++) {
		ans++;
		x -= a[i];
		if(x <= 0) break;
	}
	if(x != 0) ans--;
	cout << ans;
	return 0;
}
