#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a);i < (b);++i)
#define FORR(i, b, a) for (int i = (b) - 1;i >= 0;--i)
#define REP(i, n) for(int i = 0;i < (n);++i)
#define REPR(i, n) for(int i = (n) - 1;i >= 0;--i)
#define ITER(itr, v) for(auto itr = v.begin();itr != v.end();++itr)
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SIZE(v) int(v.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	vector<pair<ll, int>> dt(N);
	REP(i, N) cin >> dt[i].second >> dt[i].first;
	sort(dt.begin(), dt.end(), greater<pair<ll, int>>());
	vector<int> num(N + 1);
	ll sum = 0;
	ll x = 0;
	REP(i, K) {
		sum += dt[i].first;
		if (num[dt[i].second]++ == 0) ++x;
	}
	ll res = 0;
	int i = K - 1, j = K;
	while (true) {
		res = max(res, sum + x * x);
		if (x == K) break;
		while (i >= 0 && num[dt[i].second] == 1) --i;
		if (i < 0) break;
		while (j < N && num[dt[j].second] > 0) ++j;
		if (j == N) break;
		num[dt[i].second]--;
		num[dt[j].second]++;
		++x;
		sum = sum - dt[i].first + dt[j].first;
		--i;
		++j;
	}
	cout << res << endl;

	return 0;
}