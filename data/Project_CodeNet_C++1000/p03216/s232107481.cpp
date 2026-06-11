//#define NDEBUG
#include <cstddef>
#include <cstdint>
#include <vector>

using i8 = ::std::int_least8_t;
using i32 = ::std::int_least32_t;
using i64 = ::std::int_least64_t;
using u8 = ::std::uint_least8_t;
using u32 = ::std::uint_least32_t;
using u64 = ::std::uint_least64_t;
using isize = ::std::ptrdiff_t;
using usize = ::std::size_t;

template <class T = usize> class rep {
	const T f, l;

public:
	class itr {
		friend rep;
		T i;
		constexpr itr(T x) noexcept : i(x) {}

	public:
		void operator++() noexcept { ++i; }
		T operator*() const noexcept { return i; }
		bool operator!=(const itr x) const noexcept { return i != x.i; }
	};
	constexpr rep(const T first, const T last) noexcept : f(first), l(last) {}
	itr begin() const noexcept { return itr(f); }
	itr end() const noexcept { return itr(l); }
};
template <class T = usize> class revrep {
	const T f, l;

public:
	class itr {
		friend revrep;
		T i;
		constexpr itr(T x) noexcept : i(x) {}

	public:
		void operator++() noexcept { --i; }
		T operator*() const noexcept { return i; }
		bool operator!=(const itr x) const noexcept { return i != x.i; }
	};
	constexpr revrep(const T first, const T last) noexcept : f(first), l(last) {}
	itr begin() const noexcept { return itr(l - 1); }
	itr end() const noexcept { return itr(f - 1); }
};
template <class T> bool maxi(T &a, const T &b) {
	return a <= b ? (a = b, 1) : 0;
}
template <class T> bool mini(T &a, const T &b) {
	return b <= a ? (a = b, 1) : 0;
}
template <class T> bool smaxi(T &a, const T &b) {
	return b <= a ? 0 : (a = b, 1);
}
template <class T> bool smini(T &a, const T &b) {
	return a <= b ? 0 : (a = b, 1);
}
template <class T> using vec_alias = ::std::vector<T>;
template <class T> auto md_vec(usize n, const T &value) {
	return ::std::vector<T>(n, value);
}
template <class... Args> auto md_vec(usize n, Args... args) {
	return ::std::vector<decltype(md_vec(args...))>(n, md_vec(args...));
}
template <class T> const T &as_const(const T &v) noexcept { return v; }

template <class T> T difference(const T &a, const T &b) {
	return a <= b ? b - a : a - b;
}


#include <algorithm>
#include <iostream>
#include <utility>

int main() {
	usize n;
	::std::cin >> n;
	::std::vector<char> s(n);
	for (auto &e : s) {
		::std::cin >> e;
	}
	usize q;
	::std::cin >> q;
	while (q--) {
		usize k;
		::std::cin >> k;
		u64 cntall = 0,cntd = 0, cntm = 0;
		u64 ans = 0;
		for (const auto i : rep<u64>(0, n)) {
			if (i >= k) {
				if (s[i - k] == 'D') {
					--cntd;
					cntall -= cntm;
				}
				else if (s[i - k] == 'M') {
					--cntm;
				}
			}
			if (s[i] == 'C') {
				ans += cntall;
			}
			else if (s[i] == 'M') {
				cntall += cntd;
				++cntm;
			}
			else if (s[i] == 'D') {
				++cntd;
			}
		}
		::std::cout << ans << ::std::endl;
	}
	return 0;
}
