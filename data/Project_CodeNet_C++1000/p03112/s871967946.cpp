#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define LIMIT(d_in, d_min, d_max) max(d_min, min(d_max, d_in))
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

void execute()
{
	int N, M, Q;
	cin >> N >> M >> Q;

	vector<lint> s(N + 2);
	vector<lint> t(M + 2);

	s[0] = t[0] = -INF64;
	for (int i = 0; i < N; i++)
	{
		cin >> s[i + 1];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> t[i + 1];
	}

	s[N + 1] = t[M + 1] = INF64;
	for (int i = 0; i < Q; i++)
	{
		lint p;
		cin >> p;
		lint up_s = s[lower_bound(all(s), p) - s.begin()];
		lint up_t = t[lower_bound(all(t), p) - t.begin()];
		lint down_s = s[upper_bound(all(s), p) - s.begin() - 1];
		lint down_t = t[upper_bound(all(t), p) - t.begin() - 1];

		lint ans = INF64;
		ans = min(ans, max(up_s, up_t) - p);
		ans = min(ans, p - min(down_s, down_t));
		ans = min(ans, up_t - down_s + min(p - down_s, up_t - p));
		ans = min(ans, up_s - down_t + min(p - down_t, up_s - p));
		cout << ans << endl;
	}

	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}