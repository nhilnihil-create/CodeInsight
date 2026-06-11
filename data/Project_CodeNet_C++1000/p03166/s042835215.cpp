#include <cstdio>
#include <algorithm>
#include <bitset>

using i8 = std::int8_t;
using u8 = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;
using isize = std::ptrdiff_t;
using usize = std::size_t;

constexpr i32 N = 100000;
i32 dp[N];

auto main() -> i32 {
	i32 n, m;
	scanf("%d%d", &n, &m);
	std::vector<i32> rev[n];
	std::vector<i32> edge[n];

	for (i32 i = 0; i < m; i += 1) {
		i32 x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		rev[y].push_back(x);
		edge[x].push_back(y);
	}

	std::vector<i32> sorted;
	std::bitset<N> visit;

	for (i32 i = 0; i < n; i += 1) {
		if (visit[i]) {
			continue;
		}
		std::vector<i32> q;
		q.push_back(i);
		while (q.size() > 0) {
			i32 v = q.back();
			q.pop_back();
			if (v < 0) {
				sorted.push_back(~v);
				continue;
			}
			if (visit[v]) {
				continue;
			}
			visit[v] = true;
			q.push_back(~v);
			for (auto to : edge[v]) {
				if (!visit[to]) {
					q.push_back(to);
				}
			}
		}
	}

	i32 ans = 0;

	for (auto v : sorted) {
		for (auto from : rev[v]) {
			dp[from] = std::max(dp[from], dp[v] + 1);
			if (ans < dp[from]) {
				ans = dp[from];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
