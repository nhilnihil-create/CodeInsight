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

constexpr i64 MOD = 1000000007;

i64 dp[101][100001];

auto main() -> i32 {
	i32 n, k;
	scanf("%d%d", &n, &k);
	i32 a[n];
	for (i32 i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}

	dp[0][0] = 1;
	for (i32 i = 0; i < n; ++i) {
		for (i32 l = 0; l <= k; ++l) {
			dp[i + 1][l] += dp[i][l];
			i32 ub = l + a[i] + 1;
			if (ub <= k) {
				dp[i + 1][ub] -= dp[i][l];
			}
		}
		dp[i + 1][0] %= MOD;
		for (i32 j = 1; j <= k; ++j) {
			dp[i + 1][j] += dp[i + 1][j - 1];
			dp[i + 1][j] %= MOD;
		}
	}
	printf("%ld\n", (MOD + dp[n][k]) % MOD);
	return 0;
}
