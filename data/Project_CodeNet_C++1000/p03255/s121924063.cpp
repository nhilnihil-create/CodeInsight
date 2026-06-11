//B - Garbage Collector
#include<iostream>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main()
{
	ll N, X, x;
	cin >> N >> X;
	ll sum[N + 1];
	sum[0] = 0;
	for (ll i = 1; i <= N; i++) {
		cin >> x;
		sum[i] = sum[i - 1] + x;
	}

	ll ans = INF;
	for (ll k = 1; k <= N; k++) {
		ll i = N;
		ll E = (N + k)*X + sum[i] * 5;
		i -= k * 2;
		while (i > 0) {
			E += sum[i] * 2;
			i -= k;
			if (E < 0) {
				E = INF;
				break;
			}
		}
		ans = min(ans, E);
	}
	cout << ans << endl;
	return 0;
}