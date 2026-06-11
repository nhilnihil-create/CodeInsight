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
	int n; scanf("%d", &n); std::vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);

	int ans = [a, b, n] {
		int A = 0, B = 0, C = 0, D = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] & 1) A++;
			else B++;
			if(b[i] & 1) C++;
			else D++;
		}
		return (A * D + B * C) % 2;
	}();
	for(int k = 29; k > 1; k--) {
		for(int i = 0; i < n; i++) {
			a[i] &= (1 << k) - 1;
			b[i] &= (1 << k) - 1;
		}
		sort(begin(b), end(b));

		int X = 0;
		for(int i = 0; i < n; i++) {
			int A = upper_bound(begin(b), end(b), (1 << k) - a[i] - 1)
				  - lower_bound(begin(b), end(b), (1 << (k - 1)) - a[i]);
			int B = upper_bound(begin(b), end(b), (1 << (k + 1)) - a[i] - 1)
				  - lower_bound(begin(b), end(b), (1 << k) + (1 << (k - 1)) - a[i]);
			X += (A + B) % 2;
		}
		if(X & 1) ans ^= (1 << (k - 1));
	}
	printf("%d\n", ans);
	return 0;
}
