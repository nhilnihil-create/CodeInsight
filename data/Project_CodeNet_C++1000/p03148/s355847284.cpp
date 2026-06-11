#include<iostream>
#include<algorithm>
#include<map>
#include<functional>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

int N, K;
P sushi[100000];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> sushi[i].second >> sushi[i].first;
	}
	sort(sushi, sushi + N, greater<P>());

	map<int, int> M;
	ll ans = 0;
	ll kind = 0;
	for (int i = 0; i < K; i++) {
		ans += sushi[i].first;
		M[sushi[i].second]++;
		if (M[sushi[i].second] == 1)kind++;
	}
	ans += kind * kind;
	ll now = ans;
	int lpointer = K - 1, rpointer = K;
	while (1) {
		if (rpointer == N|| lpointer == -1)break;

		if (M[sushi[rpointer].second] != 0) {
			rpointer++;
			continue;
		}
		ll ad = sushi[rpointer].first;

		while (M[sushi[lpointer].second] == 1 && lpointer >= 0)lpointer--;
		if (lpointer == -1)break;
		ll er = sushi[lpointer].first;

		//if (ans <= now - (kind * kind) + (kind + 1) * (kind + 1) -er + ad) {
		now = now - (kind * kind) + (kind + 1) * (kind + 1) - er + ad;
		ans = max(ans, now);
		M[sushi[rpointer].second]++;
		M[sushi[lpointer].second]--;
		rpointer++, lpointer--;
		kind++;
		//}
	}
	cout << ans << endl;
	return 0;
}