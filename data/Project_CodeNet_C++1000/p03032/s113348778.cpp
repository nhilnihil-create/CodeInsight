#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N, K;
	cin >> N >> K;
	int V[N];
	for(int i = 0; i < N; i++) cin >> V[i];

	ll ans = 0, limit = min(N, K);
	for(int i = 0; i <= limit; i++) {
		for(int j = 0; i + j <= limit; j++) {
			vector<int> v;
			for(int a = 0; a < i; a++) v.push_back(V[a]);
			for(int a = 0; a < j; a++) v.push_back(V[N - 1 - a]);

			ll sum = accumulate(v.begin(), v.end(), 0LL);

			sort(v.begin(), v.end());
			for(int a = 0; a < min(K - i - j, (int)(v.size())); a++)
				if(v[a] >= 0)
					break;
				else
					sum -= v[a];
			ans = max(ans, sum);
		}
	}
	cout << ans << "\n";
	return 0;
}
