#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

int main() {
	int k; scanf("%d", &k);

	auto f = [](i64 x) -> i64 {
		i64 ret = x % 10;
		while(x /= 10) ret += x % 10;
		return ret;
	};
	
	std::vector<i64> ans(1, 1);
	while(ans.size() < k) {
		const i64 n = ans.back() + 1;
		
		i64 latte = 1;
		std::vector<i64> vec;
		while(latte <= n) {
			for(i64 d = 1; d < 10; d++) {
				i64 tmp = (n - n % (latte * 10LL)) + d * latte + (latte - 1);
				if(tmp < n) continue;
				vec.push_back(tmp);
			}
			latte *= 10LL;
		}
		
		latte /= 10LL;
		for(i64 d = 1; d < 100; d++) {
			i64 tmp = d * latte + latte - 1;
			if(tmp < n) continue;
			vec.push_back(tmp);
		}

		i64 nx = vec.front();
		for(auto m: vec) {
			if(nx * f(m) <= m * f(nx)) continue;
			nx = m;
		}
		ans.push_back(nx);
	}
	for(auto v: ans) printf("%lld\n", v);
	return 0;
}
