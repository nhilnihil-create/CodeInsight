#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	ll N, K;
	ll i, init;
	ll ans = 0;
	cin >> N >> K;

	if (K == 0) {
		cout << N * N << endl;
		return 0;
	}

	for (ll r = K; r <= N - 1; r++) {
		ans += N - r;
		i = 1;
		while ((init = r + (r + 1) * i) <= N) {
			ans += 1 + (N - init) / i;
			i++;
		}
	}

	cout << ans << endl;

	return 0;
}
