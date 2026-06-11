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
	i64 n, m; scanf("%lld%lld", &n, &m);
	std::vector<std::vector<int>> g(n);
	for(int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);

		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}

	std::vector<int> used(n, -1);
	std::queue<int> qu({0}); used[0] = 0;
	while(!qu.empty()) {
		auto v = qu.front(); qu.pop();

		for(auto e: g[v]) {
			if(used[e] == -1) {
				used[e] = 1 - used[v];
				qu.push(e);
				continue;
			}
			if(used[e] == used[v]) {
				printf("%lld\n", n * (n - 1) / 2 - m);
				return 0;
			}
		}
	}

	i64 A = 0, B = 0;
	for(auto v: used) {
		if(v) A++;
		else B++;
	}
	printf("%lld\n", A * B - m);
	return 0;
}
