#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N;
	cin >> N;
	int h[N];
	for(int i = 0; i < N; i++) cin >> h[i];

	int ans = h[0];
	for(int i = 1; i < N; i++) ans += max(0, h[i] - h[i - 1]);
	cout << ans;
	return 0;
}