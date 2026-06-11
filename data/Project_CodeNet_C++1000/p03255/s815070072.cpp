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

class rep {
	const usize f, l;

public:
	class itr {
		friend rep;
		usize i;
		itr(usize x) noexcept : i(x) {}

	public:
		void operator++() noexcept { ++i; }
		usize operator*() const noexcept { return i; }
		bool operator!=(const itr x) const noexcept { return i != x.i; }
	};
	rep(usize first, usize last) noexcept : f(first), l(last) {}
	itr begin() const noexcept { return itr(f); }
	itr end() const noexcept { return itr(l); }
};
class revrep {
	const usize f, l;

public:
	class itr {
		friend revrep;
		usize i;
		itr(usize x) noexcept : i(x) {}

	public:
		void operator++() noexcept { --i; }
		usize operator*() const noexcept { return i; }
		bool operator!=(const itr x) const noexcept { return i != x.i; }
	};
	revrep(usize first, usize last) noexcept : f(first), l(last) {}
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

#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <functional>

u64 mm(const u64 a) {
	return a*a;
}

int main() {
	usize n;
	u64 c;
	::std::cin >> n >> c;
	::std::vector<u32> x(n);
	for (auto &e : x)
		::std::cin >> e;
	::std::function<u64(u32)> calc=[&](const usize width)->u64 {
		u64 ret = 0;
		usize cnt = 0;
		u64 cost = 0;
		for (const auto i : revrep(0, n)) {
			if (cnt < width)
				cost += 1;
			cost += mm(cnt / width + 2) - mm(cnt / width + 1);
			++cnt;
			ret += (cost + ::std::min(cnt, width))*(x[i] - (i ? x[i - 1] : 0));
		}
		return ret + c*(width + n);
	};
	u64 ans;
	if (n == 1) {
		ans = calc(1);
	}
	else if (n == 2) {
		ans = ::std::min(calc(1), calc(2));
	}
	else {
		usize low = 1, high = n;
		while (low + 3 <= high) {
			usize l = (low + low + high) / 3;
			usize r = (low + high + high) / 3;
			if (calc(l) < calc(r))
				high = r;
			else
				low = l;
		}
		ans = ::std::min({ calc(low),calc(low + 1),calc(low + 2) });
	}
	
	::std::cout << ans << ::std::endl;
	return 0;
}
