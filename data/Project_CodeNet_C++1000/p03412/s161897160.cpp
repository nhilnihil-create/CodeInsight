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
	int n; scanf("%d", &n); std::vector<i64> a(n), b(n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]); sort(begin(a), end(a));
	for(int i = 0; i < n; i++) scanf("%lld", &b[i]); sort(begin(b), end(b));
	
	i64 ans = 0;
	for(int i = 40; i >= 0; i--) {
		i64 MOD = (1LL << i);
		std::vector<i64> A, B;
		for(auto v: a) {
			if(v >> i & 1) B.push_back(v % MOD);
			else A.push_back(v % MOD);
		}
		sort(begin(A), end(A)); sort(begin(B), end(B));
		
		i64 count = 0;
		for(auto v: b) {
			if(v >> i & 1) {
				v %= MOD;
				i64 X = upper_bound(begin(A), end(A), MOD - v - 1) - begin(A);
				i64 Y = upper_bound(begin(B), end(B), MOD - v - 1) - begin(B); Y = (i64)B.size() - Y;	
				
				count += X + Y;
				count %= 2;
			} else {
				v %= MOD;
				i64 X = upper_bound(begin(B), end(B), MOD - v - 1) - begin(B);
				i64 Y = upper_bound(begin(A), end(A), MOD - v - 1) - begin(A); Y = (i64)A.size() - Y;
				
				count += X + Y;
				count %= 2;
			}
		}
		if(count % 2LL) ans |= (1LL << i);
	}
	printf("%lld\n", ans);
	return 0;
}
