//#define NDEBUG
#include <cstddef>
#include <cstdint>
#include <vector>

namespace n91 {

	using i8 = std::int_least8_t;
	using i32 = std::int_least32_t;
	using i64 = std::int_least64_t;
	using u8 = std::uint_least8_t;
	using u32 = std::uint_least32_t;
	using u64 = std::uint_least64_t;
	using isize = std::ptrdiff_t;
	using usize = std::size_t;

	class rep {
		const usize f, l;

	public:
		class itr {
			friend rep;
			usize i;
			constexpr itr(const usize x) noexcept : i(x) {}

		public:
			void operator++() noexcept { ++i; }
			constexpr usize operator*() const noexcept { return i; }
			constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
		};
		constexpr rep(const usize first, const usize last) noexcept
			: f(first), l(last) {}
		constexpr itr begin() const noexcept { return itr(f); }
		constexpr itr end() const noexcept { return itr(l); }
	};
	class revrep {
		const usize f, l;

	public:
		class itr {
			friend revrep;
			usize i;
			constexpr itr(usize x) noexcept : i(x) {}

		public:
			void operator++() noexcept { --i; }
			constexpr usize operator*() const noexcept { return i; }
			constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
		};
		constexpr revrep(usize first, usize last) noexcept : f(--first), l(--last) {}
		constexpr itr begin() const noexcept { return itr(l); }
		constexpr itr end() const noexcept { return itr(f); }
	};
	template <class T> using vec_alias = std::vector<T>;
	template <class T> auto md_vec(const usize n, const T &value) {
		return std::vector<T>(n, value);
	}
	template <class... Args> auto md_vec(const usize n, Args... args) {
		return std::vector<decltype(md_vec(args...))>(n, md_vec(args...));
	}
	template <class T> constexpr T difference(const T &a, const T &b) {
		return a < b ? b - a : a - b;
	}

} // namespace n91

#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cassert>

namespace n91 {

	void stop(){}

	void main_() {
		usize n;
		u64 a, b;
		std::cin >> n >> a >> b;
		std::vector<usize> p(n);
		for (auto &e : p) {
			std::cin >> e;
			--e;
		}
		p.emplace_back(n);
		static constexpr u64 INF = std::numeric_limits<u64>::max();
		std::vector<u64> dp(n + 1, INF);
		for (const auto i : rep(0, n + 1)) {

			u64 acc = 0;
			usize prev = 0;
			for (const auto k : revrep(0, i)) {
				if (p[k] > p[i]) {
					acc += a;
				}
				else if (p[k] < prev) {
					acc += b;
				}
				else {
					prev = p[k];
					if (dp[k] + acc < dp[i]) {
						dp[i] = dp[k] + acc;
					}
					acc += b;
				}
			}
			if (acc < dp[i]) {
				dp[i] = acc;
			}
		}
		std::cout << dp.back() << std::endl;
		stop();
	}

} // namespace n91

int main() {
	n91::main_();
	return 0;
}
