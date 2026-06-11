#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	ll N;
	cin >> N;
	ll x[N], y[N], h[N];
	for(int i = 0; i < N; i++) cin >> x[i] >> y[i] >> h[i];
	int start;
	for(int i = 0; i < N; i++)
		if(h[i]) start = i;
	for(ll X = 0; X < 101; X++) {
		for(ll Y = 0; Y < 101; Y++) {
			bool ok = true;
			ll H = abs(X - x[start]) + abs(Y - y[start]) + h[start];
			for(ll i = 0; i < N; i++) {
				if(max(H - abs(X - x[i]) - abs(Y - y[i]), 0LL) != h[i]) {
					ok = false;
					break;
				}
			}
			if(ok) {
				cout << X << " " << Y << " " << H << "\n";
				return 0;
			}
		}
	}
	return 0;
}
