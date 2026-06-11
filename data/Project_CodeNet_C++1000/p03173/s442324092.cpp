#include <cstdio>
#include <algorithm>

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

i64 dp[400][400];
i64 a[400];
i64 cum[401];

auto dfs(i32 l, i32 r) -> i64 {
	if (dp[l][r] > 0) {
		return dp[l][r];
	}
	if (l == r) {
		return 0;
	}

	i64 x = 1LL << 60;
	for (i32 i = l; i < r; i += 1) {
		x = std::min(x, dfs(l, i) + dfs(i + 1, r));
	}
	dp[l][r] = x + cum[r + 1] - cum[l];
	return dp[l][r];
}

auto main() -> i32 {
	i32 n;
	scanf("%d", &n);
	for (i32 i = 0; i < n; i += 1) {
		scanf("%ld", a + i);
		cum[i + 1] = cum[i] + a[i];
	}
	i64 ans = dfs(0, n - 1);
	printf("%ld\n", ans);
	return 0;
}
